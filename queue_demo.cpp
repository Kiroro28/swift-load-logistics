#include <iostream>
#include <queue>
#include <string>

void runQueueDemo() {
    std::queue<std::string> loadingBay;
    loadingBay.push("Truck Alpha");
    loadingBay.push("Truck Bravo");
    loadingBay.push("Truck Charlie");
    loadingBay.push("Truck Delta");

    std::cout << "Processing Queue in FIFO order:" << std::endl;
    while (!loadingBay.empty()) {
        std::cout << "  -> Loading: " << loadingBay.front() << std::endl;
        loadingBay.pop();
    }
}
