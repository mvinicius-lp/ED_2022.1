#include <iostream>
#include "functions.hpp"

int main() {
    std::string line {};

    getline(std::cin, line);

    BTree tree(line);

    std::cout << std::endl;

    std::cout << tree.sum() << " " << tree.min() << std::endl;
    
    return 0;
}