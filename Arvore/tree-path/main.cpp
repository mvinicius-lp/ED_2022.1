#include <iostream>
#include "functions.hpp"

using namespace std;

int main() {
    string line {};

    getline(cin, line);

    BTree tree(line);

    int valor;

    cin >> valor;

    cout << endl << tree.encontra_path(valor) << endl;

    return 0;
}