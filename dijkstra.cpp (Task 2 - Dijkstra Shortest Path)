#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <string>

struct Edge {
    int to;
    int weight;
};

void runDijkstraDemo() {
    std::vector<std::string> nodes = {"Depot", "WarehouseA", "WarehouseB", "Hub_North", "Hub_South", "CustomerX"};
    int V = nodes.size();
    std::vector<std::vector<Edge>> graph(V);

    graph[0].push_back({1, 8});   // Depot -> WarehouseA (8km)
    graph[0].push_back({2, 15});  // Depot -> WarehouseB (15km)
    graph[1].push_back({3, 11});  // WarehouseA -> Hub_North (11km)
    graph[1].push_back({4, 7});   // WarehouseA -> Hub_South (7km)
    graph[2].push_back({4, 5});   // WarehouseB -> Hub_South (5km)
    graph[3].push_back({5, 6});   // Hub_North -> CustomerX (6km)
    graph[4].push_back({5, 12});  // Hub_South -> CustomerX (12km)

    std::vector<int> dist(V, INT_MAX);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

    dist[0] = 0;
    pq.push({0, 0});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (const auto& edge : graph[u]) {
            if (dist[u] + edge.weight < dist[edge.to]) {
                dist[edge.to] = dist[u] + edge.weight;
                pq.push({dist[edge.to], edge.to});
            }
        }
    }

    std::cout << "Shortest Paths from Source [Depot]:" << std::endl;
    for (int i = 0; i < V; i++) {
        std::cout << "  To " << nodes[i] << " : " << dist[i] << " km" << std::endl;
    }
}
