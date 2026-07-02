#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Structure to represent a graph edge (destination node, weight/distance)
struct Edge {
    int to;
    int weight;
};

// 1. Dijkstra's Algorithm implementation
void dijkstra(const vector<vector<Edge>>& graph, int src, const vector<string>& nodeNames) {
    int V = graph.size();
    vector<int> dist(V, INT_MAX);
    // Priority queue to store {distance, node_index}, ordered by smallest distance
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (const auto& edge : graph[u]) {
            int v = edge.to;
            int w = edge.weight;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    // Print the calculated shortest paths
    cout << "Shortest distances from Source [" << nodeNames[src] << "]:" << endl;
    for (int i = 0; i < V; i++) {
        cout << "  To " << nodeNames[i] << " : ";
        if (dist[i] == INT_MAX) {
            cout << "Unreachable" << endl;
        } else {
            cout << dist[i] << " km" << endl;
        }
    }
}

int main() {
    cout << "==================================================" << endl;
    cout << "       SWIFT-LOAD LOGISTICS SYSTEM - TASK 2       " << endl;
    cout << "==================================================" << endl;

    // ------------------------------------------------------------
    // PART A: LIFO Stack Demonstration (Cargo Loading/Unloading)
    // ------------------------------------------------------------
    cout << "\n[1] SIMULATING LIFO CARGO STACK (LOADING/UNLOADING):" << endl;
    cout << "--------------------------------------------------" << endl;
    
    stack<string> cargoStack;

    cout << "Loading cargo onto the delivery truck (Pushing to Stack):" << endl;
    string boxes[] = {"Box Alpha", "Box Bravo", "Box Charlie", "Box Delta"};
    
    for (const string& box : boxes) {
        cout << "  -> Loaded: " << box << endl;
        cargoStack.push(box);
    }

    cout << "\nUnloading cargo at destination (Popping from Stack - LIFO order):" << endl;
    while (!cargoStack.empty()) {
        cout << "  <- Unloaded: " << cargoStack.top() << endl;
        cargoStack.pop();
    }
    cout << "--------------------------------------------------" << endl;

    // ------------------------------------------------------------
    // PART B: Dijkstra's Shortest Path (Personalised Delivery Map)
    // ------------------------------------------------------------
    cout << "\n[2] DIJKSTRA'S SHORTEST PATH GENERATION:" << endl;
    cout << "--------------------------------------------------" << endl;

    // Defining 6 delivery nodes (0 to 5) 
    vector<string> nodeNames = {"Depot", "WarehouseA", "WarehouseB", "Hub_North", "Hub_South", "CustomerX"};
    int V = nodeNames.size();
    
    vector<vector<Edge>> graph(V);

    // Building adjacency list with unique edge weights 
    graph[0].push_back({1, 8});   // Depot -> WarehouseA (8km)
    graph[0].push_back({2, 15});  // Depot -> WarehouseB (15km)
    graph[1].push_back({3, 11});  // WarehouseA -> Hub_North (11km)
    graph[1].push_back({4, 7});   // WarehouseA -> Hub_South (7km)
    graph[2].push_back({4, 5});   // WarehouseB -> Hub_South (5km)
    graph[3].push_back({5, 6});   // Hub_North -> CustomerX (6km)
    graph[4].push_back({5, 12});  // Hub_South -> CustomerX (12km)

    // Print Adjacency List for documentation 
    cout << "Delivery Map Graph Structure (Adjacency List):" << endl;
    for (int i = 0; i < V; i++) {
        cout << "  " << nodeNames[i] << " links to: ";
        for (const auto& edge : graph[i]) {
            cout << nodeNames[edge.to] << " (" << edge.weight << "km) ";
        }
        cout << endl;
    }
    cout << endl;

    // Run Dijkstra algorithm from Depot (Node 0)
    dijkstra(graph, 0, nodeNames);

    cout << "--------------------------------------------------" << endl;
    cout << "Execution Completed Successfully." << endl;
    cout << "==================================================" << endl;

    return 0;
}