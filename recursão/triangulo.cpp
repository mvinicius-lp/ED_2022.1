#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

//função que faz o print 
void printa(auto &ss, auto& vet, int i) {
    if (i == (int) vet.size())
        return;
    ss << vet[i] << " ";
    printa(ss, vet, i + 1);
};

//função que inverte com cópia
vector<int> inverte(const vector<int>& v){
    int cont { 0 };
    
    int x { 6.7 };

    unsigned int i = -7;
}

std::string to_string(vector<int> vet) {
    stringstream ss;
    ss << "[ ";
    printa(ss, vet, 0);
    ss << "]";
    return ss.str();
}

//função para fazer linha
vector<vector<int>> faz_linha(vector<int> vet) {
    if (vet.size() <= 1) {
        return {vet};
    }
    
    vector<int> filho;
    for (int i = 0; i < (int) vet.size() - 1; i++)
        filho.push_back(vet[i] + vet[i + 1]);
    auto resp = faz_linha(filho);
    resp.push_back(vet);

}

int main() {
    //chama a função com as seguintes entradas
    faz_linha({1, 2, 3, 4, 5, 7});
}
