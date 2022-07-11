#include <iostream>
#include <vector>
#include "functions.hpp"

int main() {
    int nl, nc;

    std::cin >> nl >> nc;
    std::cin.ignore();

    std::vector<std::string> matriz(nl);

    for (int linha = 0; linha < nl; linha++) {
        std::getline(std::cin, matriz[linha]);
    }

    Pos inicio(0,0);
    Pos fim(0,0);

    procura_inicio_fim(matriz, inicio, fim);

    caminhar(matriz, inicio, fim);

    imprime(matriz);

    return 0;
}