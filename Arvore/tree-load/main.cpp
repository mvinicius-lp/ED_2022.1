#include <iostream>
#include "functions.hpp"

using namespace std;

int main() {
    string line{};

    getline(cin, line);

    arv tree(line);

    cout << endl;

    tree.mostrar_ordem();

    cout << endl;
    
    tree.mostra();

    return 0;
}