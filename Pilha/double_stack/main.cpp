#include <iostream>
#include <list>
#include <stack>

void coloca_prateleira(std::stack<int> &deposito, std::stack<int> &prateleira) {
    while (deposito.size() > 0) {
        prateleira.push(deposito.top());
        deposito.pop();
    }
}

int main() {
    std::stack<int> deposito {}, prateleira {};

    int size, comand, elemento;

    std::cin >> size;

    std::list<int> prints {};

    for (int i = 0; i < size; i++) {
        std::cin >> comand;

        if (comand == 1) {
            std::cin >> elemento;
            deposito.push(elemento);
        } else if (comand == 2) {
            if (prateleira.size() == 0) coloca_prateleira(deposito, prateleira);
            prateleira.pop();
        } else if (comand == 3) {
            if (prateleira.size() == 0) coloca_prateleira(deposito, prateleira);
            prints.push_back(prateleira.top());    
        }
    }

    std::cout << "=========" << std::endl;
    
    for (auto x : prints) {
        std::cout << x << std::endl;
    }

    return 0;
}