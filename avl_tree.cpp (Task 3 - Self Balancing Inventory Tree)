#include <iostream>
#include <string>
#include <algorithm>
#include <stdexcept>

struct AVLNode {
    std::string name;
    std::string type;
    double weight;
    int height;
    AVLNode *left, *right;
    AVLNode(std::string n, std::string t, double w)
        : name(n), type(t), weight(w), height(1), left(nullptr), right(nullptr) {}
};

int getHeight(AVLNode* n) { return n ? n->height : 0; }
int getBalance(AVLNode* n) { return n ? getHeight(n->left) - getHeight(n->right) : 0; }

void updateHeight(AVLNode* n) {
    if (n) n->height = 1 + std::max(getHeight(n->left), getHeight(n->right));
}

AVLNode* rotateRight(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;
    x->right = y;
    y->left = T2;
    updateHeight(y);
    updateHeight(x);
    return x;
}

AVLNode* rotateLeft(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;
    y->left = x;
    x->right = T2;
    updateHeight(x);
    updateHeight(y);
    return y;
}

AVLNode* balanceNode(AVLNode* node) {
    updateHeight(node);
    int bf = getBalance(node);
    if (bf > 1 && getBalance(node->left) >= 0) return rotateRight(node);
    if (bf > 1) { node->left = rotateLeft(node->left); return rotateRight(node); }
    if (bf < -1 && getBalance(node->right) <= 0) return rotateLeft(node);
    if (bf < -1) { node->right = rotateRight(node->right); return rotateLeft(node); }
    return node;
}

AVLNode* insertNode(AVLNode* root, std::string name, std::string type, double weight) {
    if (name.empty()) throw std::invalid_argument("Cargo name cannot be empty.");
    if (weight <= 0) throw std::invalid_argument("Cargo weight must be positive.");
    if (!root) return new AVLNode(name, type, weight);
    if (weight < root->weight) root->left = insertNode(root->left, name, type, weight);
    else root->right = insertNode(root->right, name, type, weight);
    return balanceNode(root);
}

AVLNode* searchTree(AVLNode* root, double weight) {
    if (!root || root->weight == weight) return root;
    return weight < root->weight ? searchTree(root->left, weight) : searchTree(root->right, weight);
}

void inorderPrint(AVLNode* root) {
    if (!root) return;
    inorderPrint(root->left);
    std::cout << "  - " << root->name << " (" << root->weight << " kg)" << std::endl;
    inorderPrint(root->right);
}
