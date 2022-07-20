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

    BTree() {};

    BTree(string &serial) {
        stringstream ss(serial);

        root = ext_serial(ss);
    }

    //destruir
    ~BTree() {
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

    string encontra_path(int valor) {
        return _encontra_path(root, valor);
    }

    string _encontra_path(Node* node, int valor) {
        if (node == nullptr) {
            return "";
        } else if (node->valor == valor) {
            return "x";
        }

        auto sonsE = _encontra_path(node->esquerda, valor);
        
        if (sonsE != "" && sonsE != "!") {
            return "l" + sonsE;
        }

        auto sonsD = _encontra_path(node->direita, valor);
        
        if (sonsD != "" && sonsD != "!") {
            return "r" + sonsD;
        }
        
        return "!";
    }
};