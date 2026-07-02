#include <iostream>
#include "goods.h"

// External function signatures linked from other files
void runQueueDemo();
void bubbleSort(double arr[], int n);
void quickSort(double arr[], int n, int high); // overloaded helper/handler
void runStackDemo();
void runDijkstraDemo();

// AVL Tree specific references
struct AVLNode;
AVLNode* insertNode(AVLNode* root, std::string name, std::string type, double weight);
AVLNode* searchTree(AVLNode* root, double weight);
void inorderPrint(AVLNode* root);

int main() {
    std::cout << "=== SWIFT-LOAD LOGISTICS MULTI-FILE SYSTEM ===" << std::endl;
    
    // Task 1 Bay Queue
    std::cout << "\n--- TASK 1: FIFO QUEUE DEMO ---" << std::endl;
    runQueueDemo();

    // Task 1 Weights Sort
    std::cout << "\n--- TASK 1: SORTING PARADIGMS ---" << std::endl;
    double dataset[] = {125.5, 58.0, 87.2, 210.0, 33.5, 145.0};
    int n = 6;
    bubbleSort(dataset, n);
    std::cout << "Sorted Weights (Descending): ";
    for(int i=0; i<n; i++) std::cout << dataset[i] << " ";
    std::cout << std::endl;

    // Task 2 Stack
    std::cout << "\n--- TASK 2: LIFO STACK DEMO ---" << std::endl;
    runStackDemo();

    // Task 2 Dijkstra
    std::cout << "\n--- TASK 2: DIJKSTRA ROUTING ---" << std::endl;
    runDijkstraDemo();

    // Task 3 Inventory Control AVL Tree
    std::cout << "\n--- TASK 3: AVL TREE INVENTORY ---" << std::endl;
    try {
        AVLNode* root = nullptr;
        root = insertNode(root, "Medical_Equip", "Healthcare", 140.5);
        root = insertNode(root, "Solar_Panels", "Electronics", 95.2);
        std::cout << "Inorder Tree Inventory Layout:" << std::endl;
        inorderPrint(root);
    } catch(const std::exception& e) {
        std::cout << "Error Caught: " << e.what() << std::endl;
    }

    return 0;
}
