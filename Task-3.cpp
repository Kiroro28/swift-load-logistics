#include <iostream>
#include <string>
#include <algorithm>
#include <stdexcept>

using namespace std;

// AVL Tree Node Structure [cite: 157]
struct AVLNode {
    string name;
    string type;
    double weight;
    int height;
    AVLNode* left;
    AVLNode* right;

    AVLNode(string n, string t, double w)
        : name(n), type(t), weight(w), height(1), left(nullptr), right(nullptr) {} // [cite: 163, 164, 165]
};

// Helper to get node height [cite: 169]
int getHeight(AVLNode* n) { return n ? n->height : 0; }

// Helper to get balance factor [cite: 170]
int getBalance(AVLNode* n) { return n ? getHeight(n->left) - getHeight(n->right) : 0; }

// Update height of a node [cite: 171]
void updateHeight(AVLNode* n) {
    if (n) n->height = 1 + max(getHeight(n->left), getHeight(n->right)); // [cite: 172]
}

// Right Rotate [cite: 174]
AVLNode* rotateRight(AVLNode* y) {
    AVLNode* x = y->left; // [cite: 175]
    AVLNode* T2 = x->right;
    x->right = y; // [cite: 176]
    y->left = T2;
    updateHeight(y); // [cite: 177]
    updateHeight(x);
    return x; // [cite: 178]
}

// Left Rotate [cite: 180]
AVLNode* rotateLeft(AVLNode* x) {
    AVLNode* y = x->right; // [cite: 181]
    AVLNode* T2 = y->left;
    y->left = x; // [cite: 182]
    x->right = T2;
    updateHeight(x); // [cite: 183]
    updateHeight(y);
    return y; // [cite: 184]
}

// Balance the node if it's skewed [cite: 186]
AVLNode* balance(AVLNode* node) {
    updateHeight(node); // [cite: 187]
    int bf = getBalance(node); // [cite: 188]

    // Left Left Case
    if (bf > 1 && getBalance(node->left) >= 0) return rotateRight(node); // [cite: 189]
    // Left Right Case
    if (bf > 1) { node->left = rotateLeft(node->left); return rotateRight(node); } // [cite: 190]
    // Right Right Case
    if (bf < -1 && getBalance(node->right) <= 0) return rotateLeft(node); // [cite: 191]
    // Right Left Case
    if (bf < -1) { node->right = rotateRight(node->right); return rotateLeft(node); } // [cite: 192]

    return node; // [cite: 193]
}

// Insert with input validation [cite: 195]
AVLNode* insert(AVLNode* root, string name, string type, double weight) {
    if (name.empty()) throw invalid_argument("Cargo name cannot be empty."); // [cite: 196]
    if (weight <= 0) throw invalid_argument("Cargo weight must be positive."); // [cite: 197]

    if (!root) return new AVLNode(name, type, weight); // [cite: 198]

    if (weight < root->weight) root->left = insert(root->left, name, type, weight); // [cite: 199]
    else root->right = insert(root->right, name, type, weight); // [cite: 200]

    return balance(root); // [cite: 201]
}

// Search by weight [cite: 203]
AVLNode* search(AVLNode* root, double weight) {
    if (!root || root->weight == weight) return root; // [cite: 204]
    return weight < root->weight ? search(root->left, weight) : search(root->right, weight); // [cite: 205]
}

// Inorder Traversal (Prints sorted list) [cite: 207]
void inorder(AVLNode* root) {
    if (!root) return; // [cite: 208]
    inorder(root->left); // [cite: 209]
    cout << "  - " << root->name << " [" << root->type << "] (" << root->weight << " kg)" << endl; // [cite: 210]
    inorder(root->right); // [cite: 211]
}

int main() {
    cout << "==================================================" << endl;
    cout << "       SWIFT-LOAD LOGISTICS SYSTEM - TASK 3       " << endl;
    cout << "==================================================" << endl;

    AVLNode* root = nullptr;

    // ------------------------------------------------------------
    // PART A: Valid Insertions & Inorder Traversal [cite: 215]
    // ------------------------------------------------------------
    cout << "\n[1] INSERTING VALID CARGO ITEMS INTO AVL TREE:" << endl;
    cout << "--------------------------------------------------" << endl;
    try {
        // 💡 )_(
        root = insert(root, "Laptop_Pallet", "Electronics", 120.5);
        root = insert(root, "Coffee_Beans", "Foodstuffs", 45.0);
        root = insert(root, "Office_Chairs", "Furniture", 85.2);
        root = insert(root, "Steel_Rods", "Construction", 310.0);
        root = insert(root, "Copper_Wires", "Industrial", 150.8);

        cout << "All items inserted successfully. Balanced AVL Tree built." << endl;
        cout << "\nInorder Traversal Result (Sorted by Weight automatically):" << endl;
        inorder(root);
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    cout << "--------------------------------------------------" << endl;

    // ------------------------------------------------------------
    // PART B: Error Handling Verification [cite: 215]
    // ------------------------------------------------------------
    cout << "\n[2] TESTING INPUT VALIDATION & ERROR HANDLING:" << endl;
    cout << "--------------------------------------------------" << endl;
    
    // Test Case 1: Empty Name [cite: 215]
    try {
        cout << "Testing Insertion with Empty Name..." << endl;
        root = insert(root, "", "BadCargo", 50.0);
    } catch (const invalid_argument& e) {
        cout << ">> Caught Expected Exception: " << e.what() << endl;
    }

    // Test Case 2: Negative Weight [cite: 215]
    try {
        cout << "\nTesting Insertion with Negative Weight..." << endl;
        root = insert(root, "Invalid_Box", "Fragile", -10.5);
    } catch (const invalid_argument& e) {
        cout << ">> Caught Expected Exception: " << e.what() << endl;
    }
    cout << "--------------------------------------------------" << endl;

    // ------------------------------------------------------------
    // PART C: Search Functionality [cite: 215]
    // ------------------------------------------------------------
    cout << "\n[3] TESTING AVL TREE SEARCH FUNCTION:" << endl;
    cout << "--------------------------------------------------" << endl;
    
    // Successful Search [cite: 215]
    double searchWeight1 = 85.2;
    cout << "Searching for cargo with weight " << searchWeight1 << " kg..." << endl;
    AVLNode* found = search(root, searchWeight1);
    if (found) {
        cout << ">> SUCCESS: Found item: " << found->name << " (" << found->type << ")" << endl;
    } else {
        cout << ">> NOT FOUND." << endl;
    }

    // Unsuccessful Search [cite: 215]
    double searchWeight2 = 999.0;
    cout << "\nSearching for cargo with weight " << searchWeight2 << " kg..." << endl;
    found = search(root, searchWeight2);
    if (found) {
        cout << ">> SUCCESS: Found item: " << found->name << endl;
    } else {
        cout << ">> RESULT: Node not found (nullptr returned as expected)." << endl;
    }

    cout << "--------------------------------------------------" << endl;
    cout << "Execution Completed Successfully." << endl;
    cout << "==================================================" << endl;

    return 0;
}