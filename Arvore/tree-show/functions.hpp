//funções
#pragma once

#include <iostream>
#include <sstream>

using namespace std;

struct Node {
    int valor;
    Node* esquerda;
    Node* direita;

    Node(int valor, Node* esquerda = nullptr, Node* direita = nullptr) : valor(valor), esquerda(esquerda), direita(direita) {}
};

struct BTree {
    Node* root {nullptr};

    BTree() {}

    BTree(string &serial) {      
        stringstream ss(serial);
        
        this->root = ext_serial(ss);
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

    ~BTree() {
        __Destruir(this->root);
    }
    //destruir
    void __Destruir(Node* node) {
        if (node == nullptr) {
            return;
        }
        __Destruir(node->esquerda);
        __Destruir(node->direita);

        delete node;
    }

    void mostra() {
        __mostra(this->root);
    }

    void __mostra(Node* node, int level = 0) {
        if (node == nullptr) {
            cout << string(level * 4, '.')  << "#" << endl;
            return;
        }

        if (node->esquerda != nullptr || node->direita != nullptr) {
            __mostra(node->esquerda, level + 1);

            cout << string(level * 4, '.') << node->valor << endl;

            __mostra(node->direita, level + 1);

            return;
        } 
        
        cout << string(level * 4, '.') << node->valor << endl;
    }
};