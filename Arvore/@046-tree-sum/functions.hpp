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

    BTree() {}

    BTree(std::string &serial) {
        std::stringstream ss(serial);
        
        this->root = extract_serial(ss);
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
        std::string element {};
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

    int sum() {
        return __sum(root);
    }

    int __sum(Node* node) {
        if (node == nullptr) {
            return 0;
        }

        return __sum(node->left) + __sum(node->right) + node->value;
    }

    int min() {
        return __min(root);
    }

    int __min(Node* node) {
        if (node == nullptr) {
            return 0;
        }

        int value_min {node->value};

        if (node->left != nullptr) {
            value_min = std::min(value_min, __min(node->left));
        } 

        if (node->right != nullptr) {
            value_min = std::min(value_min, __min(node->right));
        }

        return value_min;
    }
};