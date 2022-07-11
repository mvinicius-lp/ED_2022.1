#include <iostream>
#include <list>

std::list<int>::iterator esfaquear(std::list<int> &rodinha, std::list<int>::iterator &espadachim) {   
    if (++espadachim == rodinha.end()) {
        espadachim = rodinha.begin();
    }

    espadachim = rodinha.erase(espadachim);

    if (espadachim == rodinha.end()) {
        if (rodinha.size() != 0) {
            espadachim = rodinha.begin();
        }          
    }  

    return espadachim;
}

void imprime(std::list<int> fila, int espada) {
    std::cout << "[ ";

    for (auto i : fila) {
        std::cout << i;

        if (i == espada) {
            std::cout << ">";
        }

        std::cout << " ";
    }

    std::cout << " ]\n";
}

int main() {
    int qtdPessoas {}, espada {};

    std::cin >> qtdPessoas >> espada;
    std::cin.ignore();
    std::cout << std::endl;

    std::list<int> fila {};

    for (int preenche = 1; preenche <= qtdPessoas; preenche++) {
        fila.push_back(preenche);
    }
    
    auto itEspadachim = fila.begin();

    for (auto it = fila.begin(); it != fila.end(); it++) {
        if (*it == espada) {
            itEspadachim = it;
            break;
        }
    }

    while (true) {
        imprime(fila, espada);

        if (fila.size() == 1) {
            break;
        } 

        itEspadachim = esfaquear(fila, itEspadachim);

        espada = *itEspadachim;
    }
}