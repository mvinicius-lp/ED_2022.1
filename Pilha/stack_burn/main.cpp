#include <iostream>
#include <vector>
#include "functions.hpp"

using namespace std;

int main() {
    int nl, nc, ini_l, ini_c;

   cin >> nl >> nc >> ini_l >> ini_c;

   vector<std::string> floresta (nl);

    for (auto linha = 0; linha < nl; linha++) {
       cin >> floresta[linha];
    }

    queimar(floresta, Pos(ini_l, ini_c));

    imprime(floresta);

    return 0;
}