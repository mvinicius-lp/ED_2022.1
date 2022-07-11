#include <iostream>
#include <sstream>
#include "functions.hpp"

int main() {
    std::string line{};

    getline(std::cin, line);

    BTree tree(line);

    getline(std::cin, line);

    std::stringstream ss(line);

    int value;

    std::cout << std::endl;
    
    while (ss >> value) {
        Node* node = tree.find(value);


        if (node != nullptr) {
            std::cout << tree.getHigh(node) << " " << tree.getDeep(value) << std::endl;
        } else {
            std::cout << "-1" << std::endl;
        }
    }

    return 0;
}