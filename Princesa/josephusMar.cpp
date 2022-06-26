#include <iostream>
#include <vector>

using namespace std;

int acha_prox_vivo(vector<int>& vet, int pos){
    do{
        pos = (pos + 1) % vet.size();
    }while(vet[pos] == false);
    return pos; //retorna a posicao do proximo elemento vivo
}

void imprimi_vet(vector<int> vet, int espada){
    for(int i = 1; i < vet.size(); i++){
        cout << i << (i == espada? "> " : "  ");
    }
    cout << endl;
}

int main(){

    int tam {}, espada {};
    cin >> tam;
    cin >> espada;

    vector<int> vet(tam, true);
    espada = espada - 1;

    int qtd = vet.size() - 1;

    while(qtd--) {
        imprimi_vet(vet, espada);
        espada = acha_prox_vivo(vet, espada);
        vet[espada] = false;
        espada = acha_prox_vivo(vet, espada);
    }
    cout << "vencedor" " " << espada << endl;
}