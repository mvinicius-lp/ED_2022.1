#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

list<char> criar_texto() {
    string line {};

    getline(cin, line);

    list<char> texto {};

    int contador = 0;

    for (auto it = line.begin(); it != line.end(); it++) {
        if (contador == 0) {
            if (*it == '<' || *it == '>' || *it == 'B' || *it == 'D') {
                texto.push_back('|');
                contador++;
            }
        }
         
        texto.push_back((*it));

        if (it + 1 == line.end()) {
            if (contador == 0) {
                texto.push_back('|');
            }
            texto.push_back('\n');

            break;
        }
    }

    return texto;
}

void imprime_texto(list<char> &texto) {
    for (auto &elemento : texto) {
        cout << elemento;
    }
}

void edita_texto(list<char> &texto) {
    auto cursor = texto.begin();
    int count = 0;

    list<char> caracteres {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'x', 'y', 'w', 'z', '-'};

    for (auto it = texto.begin(); it != texto.end(); it++) {
        for (auto it = texto.begin(); it != texto.end(); it++) {
            if (*it == '|') {
                cursor = it;
            }
        }
        
        if (*it == 'R') {
            *it = '\n';
        } else if (*it == 'B') {
            if (*cursor != texto.front()) {
                cursor = texto.erase(--cursor);

                it = texto.erase(it);
                
                --it;
            } else {
                it = texto.erase(it);
                
                --it;
            }
        } else if (*it == 'D') {
            if (*cursor != texto.back()) {
                texto.erase(++cursor);

                it = texto.erase(it);
                
                --it;
            } else {
                it = texto.erase(it);
                
                --it;
            }
        } else if (*it == '>') {
            if (*cursor != texto.back()) {
                if (*(next(cursor)) == '>') {
                    while (it != prev(texto.end())) {
                        it = texto.erase(it);
                    }
                    break;
                }
                
                auto elemento = ++cursor;

                cursor = texto.erase(cursor);
                texto.insert(--cursor, *elemento);

                it = texto.erase(it);
                
                --it;
                ++count; 
            } else {
                it = texto.erase(it);
                
                --it;
            }
        } else if (*it == '<') {
            if (*cursor != texto.front()) {
                auto elemento = --cursor;
                
                cursor = texto.erase(cursor);
                texto.insert(++cursor, *elemento);

                it = texto.erase(it);
                
                --it;

                ++count;
            } else {
                it = texto.erase(it);
                
                --it;
            }
        } else if (count >= 1) {
            if (find(caracteres.begin(), caracteres.end(), *it) != caracteres.end()) {
                texto.insert(cursor, *it);

                it = texto.erase(it);

                --it;
            }
        }
    }

    imprime_texto(texto);
}