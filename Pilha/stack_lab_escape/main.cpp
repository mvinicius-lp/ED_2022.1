#include <iostream>
#include <vector>
#include "functions.hpp"

using namespace std;

int main() {
    int nl, nc;

    cin >> nl >> nc;
    cin.ignore();

    vector<string> matriz(nl);

    for (int linha = 0; linha < nl; linha++) {
        getline(cin, matriz[linha]);
    }

    Pos inicio(0,0);
    Pos fim(0,0);

    procura_inicio_fim(matriz, inicio, fim);

    caminhar(matriz, inicio, fim);

    imprime(matriz);

    return 0;
}