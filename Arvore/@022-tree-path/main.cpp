#include <iostream>
#include "functions.hpp"

int main() {
    std::string line {};

    getline(std::cin, line);

    BTree tree(line);

    int value;

    std::cin >> value;

    std::cout << std::endl << tree.find_path(value) << std::endl;

    return 0;
}