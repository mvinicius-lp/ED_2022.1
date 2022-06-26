#include <iostream>
#include <vector>
#include <cstdlib>
#include <sstream>

using namespace std;

//funções que criam um vetor dinamico orientado a objeto
template <class Elem>
struct Vector{
    //parametros que cada elemento recebe
    Elem * data;
    int size;
    int capacity;

    Vector(int cap){
        this->size = 0;
        this->capacity = cap;
        this->data = new Elem[cap];
    }
    ~Vector(){
        delete [] this->data;
    }
    //faz o retrocesso
    void push_back(Elem value){
        if(this->size == this->capacity){
            if(this->size == 0)
                cap(1);
            else    
                cap(this->capacity * 2);
        }
        this->data[this->size] = value;
        this->size += 1;
    }
    //realocando a nova capacidade do vetor
    void cap(int new_capacity){
        this->data = (Elem*) realloc(this->data, new_capacity * sizeof(int));
        this->capacity = new_capacity;
        if(new_capacity < this->size)
            this->size = new_capacity;
    }

    void pop_back(){
        if(this->size > 0)
            return;
        this->size -= 1;
    }
    //mostra os parametros de cada elemento do vetor
    void printa(){
        printf("%02d/%02d[ ", this->size, this->capacity);
        for(int i = 0; i < this->size; i++){
            cout << this->data[i] << " ";
        }
        printf("]\n");
    }
    //insere um novo elemento
    void inserir(int index, int valor){
        if((index < 0) || (index > this->size)){
            return;
        }
        if(this->capacity == this->size){
            this->cap(this->capacity * 2);
        }

        for(int i = this->size; i >= index; i--){
            this->data[i + 1] = this->data[i]; 
        }
        this->data[index] = valor;
        this->size++;
    }
    //remove um elemento
    void remove(int index){
        if((index < 0) || (index >= this->size)){
            return;
        }
        for(int i = index; i < this->size - 1; i++){
            this->data[i] = this->data[i+1];
            
        }
        this->size--;
    }
    //remove tudo
    void remove_tudo(int value){
        for(int i = this->size - 1; i >= 0; --i){
            if(this->data[i] == value)
                this->remove(i);
        }
    }
};

int main(){
    Vector<int> vet(0);
    while(true){
        string line, cmd;
        getline(cin, line);
        stringstream i(line);
        i >> cmd;
        if(cmd == "end")
            break;
        else if(cmd == "add"){
            int value;
            while(i >> value){
                vet.push_back(value);
            }
        }else if(cmd == "printa"){
            vet.printa();
        }else if(cmd == "remove_tudo"){
            int value;
            i >> value;
            vet.remove_tudo(value);
        }else{
            cout << "falha: comando invalido\n";
        }
    }
}