#pragma once

#include <iostream>
#include <sstream>


struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int value, Node* left = nullptr, Node* right = nullptr) : value(value), left(left), right(right) {}
};

struct BTree {
    Node* root {nullptr};

    BTree() {};

    BTree(std::string &serial) {
        std::stringstream ss(serial);

        root = extract_serial(ss);
    }

    ~BTree() {
        __destroy(this->root);
    }

    void __destroy(Node* node) {
        if (node == nullptr) {
            return;
        }

        __destroy(node->left);
        __destroy(node->right);

        delete node;
    }

    Node* extract_serial(std::stringstream &ss) {
        std::string element{};
        ss >> element;

        if (element == "#") {
            return nullptr;
        }

        int value = std::stoi(element);

        Node* node = new Node(value);

        node->left = extract_serial(ss);
        node->right = extract_serial(ss);

        return node;
    }

    Node* find(int value) {
        return _find(value, root); 
    }

    Node* _find(int value, Node* node) {
        if (node == nullptr) return nullptr;
        else if (node->value == value) return node;

        auto sonsL = _find(value, node->left);
        auto sonsR = _find(value, node->right);

        return sonsL != nullptr ? sonsL : sonsR;
    }

    int getHigh(Node* node) {
        if (node == nullptr) {
            return 0;
        } 

        int sonsL = getHigh(node->left);
        int sonsR = getHigh(node->right);

        return 1 + std::max(sonsL, sonsR);
    }

    int getDeep(int value) {
        return _getDeep(value, root);
    }

    int _getDeep(int value, Node* node) {
        if (node == nullptr) {
            return 0;
        } else if (node->value == value) {
            return 1;
        }

        int sonsL = _getDeep(value, node->left);
        int sonsR = _getDeep(value, node->right);

        return sonsL == sonsR ? 0 : std::max(sonsL, sonsR) + 1;
    }
};