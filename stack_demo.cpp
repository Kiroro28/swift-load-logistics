#include <iostream>
#include <stack>
#include <string>

void runStackDemo() {
    std::stack<std::string> cargoStack;
    std::string boxes[] = {"Box A (Alpha)", "Box B (Bravo)", "Box C (Charlie)", "Box D (Delta)"};

    std::cout << "Loading Cargo onto the Truck (Pushing):" << std::endl;
    for (const std::string& box : boxes) {
        std::cout << "  [+] Pushed: " << box << std::endl;
        cargoStack.push(box);
    }

    std::cout << "\nUnloading Cargo at Destination (Popping - LIFO):" << std::endl;
    while (!cargoStack.empty()) {
        std::cout << "  [-] Popped: " << cargoStack.top() << std::endl;
        cargoStack.pop();
    }
}
