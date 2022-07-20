#include <iostream>
#include "functions.hpp"

using namespace std;

int main() {
    string line {};

    getline(cin, line);

    BTree tree(line);

    cout << endl;
    
    tree.mostra();
    
    return 0;
}