#pragma once

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void imprime(vector<string> &matriz) {
    cout << "=======\n";

    for(auto percorre : matriz)
        cout << percorre << endl;
}

struct Pos {
    int l, c;

    Pos(int l, int c) : l(l), c(c) {}
};

vector<Pos> vizinhos(Pos p) {
    auto [l,c] = p;

    return {{l, c - 1}, {l - 1, c}, {l, c + 1}, {l + 1, c}};
}
//queimar
void queimar(vector<string> &matriz, Pos p) {
    int nl = matriz.size();
    int nc = matriz[0].size();

    auto [l,c] = p;

    if (matriz[l][c] != '#') {
        return;
    }

    stack<Pos> queimando {};

    matriz[l][c] = 'o';

    queimando.push(p);

    while (queimando.empty() != true) {     
        bool queimou {false};
        
        for (auto elemento : vizinhos(queimando.top())) {
            if (elemento.l >= nl || elemento.c >= nc || elemento.l < 0 || elemento.c < 0){
                continue;
            } else if (matriz[elemento.l][elemento.c] == '#') {
                matriz[elemento.l][elemento.c] = 'o';
                queimando.push(elemento);
                queimou = true;
                break;
            }
        }

        if (!queimou) queimando.pop();
    }
}   
