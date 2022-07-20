#include <iostream>
#include "functions.hpp"

using namespace std;

int main() {
    string line {};

    getline(cin, line);

    arv tree(line);

    cout << endl;

    cout << tree.soma() << " " << tree.min() << endl;
    
    return 0;
}