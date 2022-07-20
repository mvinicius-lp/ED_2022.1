//funções
#pragma once

#include <iostream>
#include <sstream>

using namespace std;
//define o nó
struct Node {
    int valor;
    Node* esquerda;
    Node* direita;

    Node(int valor, Node* esquerda = nullptr, Node* direita = nullptr) : valor(valor), esquerda(esquerda), direita(direita) {}
};

struct arv {
    Node* root {nullptr};

    arv() {}

    arv(string &serial) {      
        stringstream ss(serial);
        
        this->root = ext_serial(ss);
    }

    ~arv() {
        destruir(this->root);
    }

    void destruir(Node* node) {
        if (node == nullptr) {
            return;
        }

        destruir(node->esquerda);
        destruir(node->direita);

        delete node;
    }

    Node* ext_serial(stringstream &ss) {
        string elemento {};
        ss >> elemento;

        if (elemento == "#") {
            return nullptr;
        }
        
        int valor = stoi(elemento);
        
        Node* node = new Node(valor);

        node->esquerda = ext_serial(ss);
        node->direita = ext_serial(ss); 
        
        return node;
    }

    ~arv() {
        destruir(this->root);
    }

    void destruir(Node* node) {
        if (node == nullptr) {
            return;
        }

        destruir(node->esquerda);
        destruir(node->direita);

        delete node;
    }

    void mostra() {
        mostrar(this->root);
    }

    void mostrar(Node* node, string heranca = "") {
        if(node != nullptr && (node->esquerda != nullptr || node->direita != nullptr)) {
            mostrar(node->esquerda, heranca + "l");
        } 

        for (int index = 0; index < (int) heranca.size() - 1; index++) {
            cout << (heranca[index] != heranca[index + 1] ? "│   " : "    ");
        }

        if (heranca != "") {
            cout << (heranca.back() == 'l' ? "┌───" : "└───");
        }

        if (node == nullptr) {
            cout << "#" << endl;
            return;
        }

        cout << node->valor << endl;

        if (node != nullptr && (node->esquerda != nullptr || node->direita != nullptr)) {
            mostrar(node->direita, heranca + "r");
        }
    }

    void mostrar_ordem() {
        cout << "[ ";
        
        _mostra_ordem(root);

        cout << "]\n";
    }

    void _mostra_ordem(Node * node) {
        if(node == nullptr) {
            return;
        }

        _mostra_ordem(node->esquerda);

        cout << node->valor << " ";

        _mostra_ordem(node->direita);
    }
};