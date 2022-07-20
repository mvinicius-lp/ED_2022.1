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
//somas
    int soma() {
        return somar(root);
    }

    int somar(Node* node) {
        if (node == nullptr) {
            return 0;
        }

        return somar(node->esquerda) + somar(node->direita) + node->valor;
    }

    int min() {
        return minimo(root);
    }
//retornar o minimo
    int minimo(Node* node) {
        if (node == nullptr) {
            return 0;
        }

        int valor_min {node->valor};

        if (node->esquerda != nullptr) {
            valor_min = min(valor_min, minimo(node->esquerda));
        } 

        if (node->direita != nullptr) {
            valor_min = min(valor_min, minimo(node->direita));
        }

        return valor_min;
    }
};