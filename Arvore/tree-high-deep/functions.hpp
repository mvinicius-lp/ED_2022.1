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

    arv() {};

    arv(string &serial) {
        stringstream ss(serial);

        root = ext_serial(ss);
    }
    //destruir raiz
    ~arv() {
        destruir(this->root);
    }
    //destruir nó
    void destruir(Node* node) {
        if (node == nullptr) {
            return;
        }

        destruir(node->esquerda);
        destruir(node->direita);

        delete node;
    }

    Node* ext_serial(stringstream &ss) {
        string elemento{};
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
    //encontrar passando o valor
    Node* encontrar(int valor) {
        return _encontrar(valor, root); 
    }

    Node* _encontrar(int valor, Node* node) {
        if (node == nullptr) return nullptr;
        else if (node->valor == valor) return node;

        auto sonsE = _encontrar(valor, node->esquerda);
        auto sonsD = _encontrar(valor, node->direita);

        return sonsE != nullptr ? sonsE : sonsD;
    }

    int getCima(Node* node) {
        if (node == nullptr) {
            return 0;
        } 

        int sonsE = getCima(node->esquerda);
        int sonsD = getCima(node->direita);

        return 1 + max(sonsE, sonsD);
    }

    int getBaixo(int valor) {
        return _getBaixo(valor, root);
    }

    int _getBaixo(int valor, Node* node) {
        if (node == nullptr) {
            return 0;
        } else if (node->valor == valor) {
            return 1;
        }

        int sonsE = _getBaixo(valor, node->esquerda);
        int sonsD = _getBaixo(valor, node->direita);

        return sonsE == sonsD ? 0 : max(sonsE, sonsD) + 1;
    }
};