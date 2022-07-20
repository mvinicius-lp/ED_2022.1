#include <iostream>
#include <sstream>
#include "functions.hpp"

using namespace std;

int main() {
   string line{};

    getline(cin, line);

    arv tree(line);

    getline(cin, line);

   stringstream ss(line);

    int valor;

   cout <<endl;
    
    while (ss >> valor) {
        Node* node = tree.encontrar(valor);
        if (node != nullptr) {
           cout << tree.getCima(node) << " " << tree.getBaixo(valor) <<endl;
        } else {
           cout << "-1" <<endl;
        }
    }
    return 0;
}