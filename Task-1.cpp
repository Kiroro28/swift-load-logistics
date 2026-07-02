#include <iostream>
#include <string>
#include <queue>
#include <stdexcept>
#include <algorithm>

using namespace std;

// 1. Goods Class with Encapsulation
class Goods {
private:
    string name;
    string type;
    double weight; // Weight in kg (must be > 0)

public:
    Goods(string n, string t, double w) : name(n), type(t) {
        setWeight(w);
    }

    void setWeight(double w) {
        if (w > 0) {
            weight = w;
        } else {
            throw invalid_argument("Weight must be positive.");
        }
    }

    double getWeight() const { return weight; }
    string getName() const { return name; }
    string getType() const { return type; }

    void display() const {
        cout << name << " | " << type << " | " << weight << " kg" << endl;
    }
};

// 2. Bubble Sort (Descending Order)
void bubbleSort(double arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// 3. QuickSort Helper: Partition (Descending Order)
int partition(double arr[], int low, int high) {
    double pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] > pivot) { // '>' for descending order
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// QuickSort Main Function
void quickSort(double arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Utility function to print an array
void printArray(double arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " kg";
        if (i < n - 1) cout << ", ";
    }
    cout << endl;
}

int main() {
    cout << "==================================================" << endl;
    cout << "       SWIFT-LOAD LOGISTICS SYSTEM - TASK 1       " << endl;
    cout << "==================================================" << endl;

    // ------------------------------------------------------------
    // PART A: FIFO Queue Demonstration (Truck Loading Bay)
    // ------------------------------------------------------------
    cout << "\n[1] SIMULATING FIFO TRUCK QUEUE (LOADING BAY):" << endl;
    cout << "--------------------------------------------------" << endl;
    
    queue<string> loadingBay;
    
    // Adding trucks to the queue (EnQueue)
    loadingBay.push("Truck A");
    loadingBay.push("Truck B");
    loadingBay.push("Truck C");
    loadingBay.push("Truck D");

    cout << "Trucks arrived and entered the queue." << endl;
    cout << "Processing queue in FIFO order..." << endl;
    
    // Removing and processing trucks (DeQueue)
    while (!loadingBay.empty()) {
        cout << "Loading: " << loadingBay.front() << endl;
        loadingBay.pop();
    }
    cout << "--------------------------------------------------" << endl;


    // ------------------------------------------------------------
    // PART B: Dataset & Sorting Algorithms
    // ------------------------------------------------------------
    cout << "\n[2] COMPARING SORTING ALGORITHMS (DESCENDING WEIGHTS):" << endl;
    cout << "--------------------------------------------------" << endl;

    // 💡 တခြားသူများနှင့် မတူစေရန် ဤအောက်က အလေးချိန်ဂဏန်းများကို သင်ကြိုက်သလို ပြောင်းလဲနိုင်ပါသည်။
    double originalDataset[] = { 125.5, 58.0, 87.2, 210.0, 33.5, 145.0, 99.8, 66.1, 182.0, 75.0, 91.3, 130.2 };
    int n = sizeof(originalDataset) / sizeof(originalDataset[0]);

    cout << "Original Unsorted Dataset:" << endl;
    printArray(originalDataset, n);
    cout << "--------------------------------------------------" << endl;

    // Create copies of the dataset for individual sorting algorithms
    double bubbleData[12];
    double quickData[12];
    for(int i = 0; i < n; i++) {
        bubbleData[i] = originalDataset[i];
        quickData[i] = originalDataset[i];
    }

    // --- Bubble Sort Run ---
    cout << "\nExecuting Bubble Sort..." << endl;
    bubbleSort(bubbleData, n);
    cout << "Bubble Sort Result (Descending):" << endl;
    printArray(bubbleData, n);

    // --- QuickSort Run ---
    cout << "\nExecuting QuickSort..." << endl;
    quickSort(quickData, 0, n - 1);
    cout << "QuickSort Result (Descending):" << endl;
    printArray(quickData, n);
    
    cout << "--------------------------------------------------" << endl;
    cout << "Execution Completed Successfully." << endl;
    cout << "==================================================" << endl;

    return 0;
}