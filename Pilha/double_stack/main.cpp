#include <iostream>
#include <list>
#include <stack>

using namespace std;

void coloca_prateleira(stack<int> &deposito, stack<int> &prateleira) {
    while (deposito.tam() > 0) {
        prateleira.push(deposito.top());
        deposito.pop();
    }
}

int main() {
    stack<int> deposito {}, prateleira {};

    int tam, comando, elemento;

    cin >> tam;

    list<int> prints {};

    for (int i = 0; i < tam; i++) {
        cin >> comando;

        if (comando == 1) {
            cin >> elemento;
            deposito.push(elemento);
        } else if (comando == 2) {
            if (prateleira.tam() == 0) coloca_prateleira(deposito, prateleira);
            prateleira.pop();
        } else if (comando == 3) {
            if (prateleira.tam() == 0) coloca_prateleira(deposito, prateleira);
            prints.push_back(prateleira.top());    
        }
    }

    cout << "=========" << endl;
    
    for (auto x : prints) {
        cout << x << endl;
    }

    return 0;
}