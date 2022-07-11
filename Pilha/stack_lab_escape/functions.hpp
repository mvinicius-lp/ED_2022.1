#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <stack>

void imprime(std::vector<std::string> &matriz) {
    std::cout << "=======\n";

    for(auto percorre : matriz)
        std::cout << percorre << std::endl;
}

struct Pos{
    int l, c;

    Pos(int l, int c) : l(l), c(c) {}

    bool operator==(Pos x) {
        if (x.l == this->l && x.c == this->c) {
            return true;
        }
        return false;
    }
};

void procura_inicio_fim(std::vector<std::string> &lab, Pos &inicio, Pos &final) {
    for (int l = 0; l < int (lab.size() - 1); l++) {
        for (int c = 0; c < int (lab[0].size() - 1); c++) {
            if (lab[l][c] == 'I') {
                lab[l][c] = ' ';
                inicio.l = l;
                inicio.c = c;
            }
            if (lab[l][c] == 'F') {
                lab[l][c] = ' ';
                final.l = l;
                final.c = c;
            }
        }
    }
}

std::vector<Pos> vizinhos(Pos p) {
    auto [l,c] = p;

    return {{l, c - 1}, {l - 1, c}, {l, c + 1}, {l + 1, c}};
}

void caminhar(std::vector<std::string> &matriz, Pos &inicio, Pos &fim) {
    int nl = matriz.size();
    int nc = matriz[0].size();

    auto [l,c] = inicio;

    std::stack<Pos> caminhando;
    std::stack<std::list<Pos>> neigs;

    matriz[l][c] = '.';

    caminhando.push(inicio);

    while (caminhando.empty() != true) {
        std::list<Pos> vizinhos_atuais {};
        
        if (caminhando.top() == fim) {
            return;
        };

        for (auto elemento : vizinhos(caminhando.top())) {
            if (elemento.l >= nl || elemento.c >= nc || elemento.l < 0 || elemento.c < 0){
                continue;
            } else if (matriz[elemento.l][elemento.c] == ' ') {
                vizinhos_atuais.push_back(elemento);
            }
        }
        
        if(vizinhos_atuais.empty()) {
            matriz[caminhando.top().l][caminhando.top().c] = ' ';
            caminhando.pop();

            while (neigs.top().empty() == true) {
                neigs.pop();
                matriz[caminhando.top().l][caminhando.top().c] = ' ';
                caminhando.pop();
            }
            
            caminhando.push(neigs.top().back());
            neigs.top().pop_back();
            matriz[caminhando.top().l][caminhando.top().c] = '.';
        } else {
            caminhando.push(vizinhos_atuais.back());
            vizinhos_atuais.pop_back();
            neigs.push(vizinhos_atuais);
            matriz[caminhando.top().l][caminhando.top().c] = '.';
        }

        imprime(matriz);

        getchar();

    }
}
