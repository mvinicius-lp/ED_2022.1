#include <iostream>
#include "functions.hpp"

int main() {
    std::string line{};

    getline(std::cin, line);

    BTree tree(line);

    std::cout << std::endl;

    tree.show_in_order();

    std::cout << std::endl;
    
    tree.show();

    return 0;
}