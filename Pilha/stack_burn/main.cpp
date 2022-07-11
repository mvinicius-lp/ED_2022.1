#include <iostream>
#include <vector>
#include "functions.hpp"

int main() {
    int nl, nc, ini_l, ini_c;

    std::cin >> nl >> nc >> ini_l >> ini_c;

    std::vector<std::string> floresta (nl);

    for (auto linha = 0; linha < nl; linha++) {
        std::cin >> floresta[linha];
    }

    queimar(floresta, Pos(ini_l, ini_c));

    imprime(floresta);

    return 0;
}