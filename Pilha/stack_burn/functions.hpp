#pragma once

#include <iostream>
#include <vector>
#include <stack>

void imprime(std::vector<std::string> &matriz) {
    std::cout << "=======\n";

    for(auto percorre : matriz)
        std::cout << percorre << std::endl;
}

struct Pos {
    int l, c;

    Pos(int l, int c) : l(l), c(c) {}
};

std::vector<Pos> vizinhos(Pos p) {
    auto [l,c] = p;

    return {{l, c - 1}, {l - 1, c}, {l, c + 1}, {l + 1, c}};
}

void queimar(std::vector<std::string> &matriz, Pos p) {
    int nl = matriz.size();
    int nc = matriz[0].size();

    auto [l,c] = p;

    if (matriz[l][c] != '#') {
        return;
    }

    std::stack<Pos> queimando {};

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
