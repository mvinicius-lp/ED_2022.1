#include <iostream>
#include <list>

std::list<int>::iterator esfaquear(std::list<int> &rodinha, std::list<int>::iterator &espadachim) {   
    if (*espadachim < 0) {
        if (espadachim == rodinha.begin()) {
            if (rodinha.size() > 1) {
                espadachim = std::prev(rodinha.end());
                espadachim = std::prev(rodinha.erase(espadachim));
            }
        } else if (std::prev(espadachim) == rodinha.begin()) {
            rodinha.erase(std::prev(espadachim));
            espadachim = std::prev(rodinha.end());
        } else {
            espadachim = std::prev(rodinha.erase(std::prev(espadachim)));
        }
    } else {
        if (++espadachim == rodinha.end()) {
            espadachim = rodinha.begin();
        }

        espadachim = rodinha.erase(espadachim);

        if (espadachim == rodinha.end()) {
            if (rodinha.size() != 0) {
                espadachim = rodinha.begin();
            }          
        }  
    }

    return espadachim;
}

void imprime(std::list<int> fila, int espada) {
    std::cout << "[ ";

    for (auto i : fila) {
        if (i < 0 && i == espada) {
            std::cout << "<" << i;
        } else {
            std::cout << i;

            if (i == espada) {
                std::cout << ">";
            }
        }
    
        std::cout << " ";
    }

    std::cout << " ]\n";
}

int main() {
    int qtdPessoas {}, espada {}, fase {};

    std::cin >> qtdPessoas >> espada >> fase;
    std::cin.ignore();
    std::cout << std::endl;

    std::list<int> fila {};

    for (int preenche = 1; preenche <= qtdPessoas; preenche++) {
        if (fase == -1) {
            if (espada == preenche) espada *= -1;
            fila.push_back(preenche * (-1));
            fase *= -1;
        } else {
            fila.push_back(preenche);
            fase *= -1; 
        }
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