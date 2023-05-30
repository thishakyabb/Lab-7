#include <iostream>
#include <vector>
#include <queue>
#include <limits>

#define INFINITY std::numeric_limits<int>::max()

struct Vertex {
    int index;
    int time;

    Vertex(int i, int t) : index(i), time(t) {}
};

struct CompareVertex {
    bool operator()(const Vertex& v1, const Vertex& v2) {
        return v1.time > v2.time;
    }
};

void dijkstraShortestPaths(std::vector<std::vector<int>>& graph, int source) {
    int V = graph.size();
    std::vector<int> time(V, INFINITY);
    std::vector<bool> visited(V, false);

    time[source] = 0;

    std::priority_queue<Vertex, std::vector<Vertex>, CompareVertex> pq;
    pq.push(Vertex(source, 0));

    while (!pq.empty()) {
        int u = pq.top().index;
        pq.pop();

        if (visited[u])
            continue;

        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] != INFINITY &&
                time[u] + graph[u][v] < time[v]) {
                time[v] = time[u] + graph[u][v];
                pq.push(Vertex(v, time[v]));
            }
        }
    }

    int total = 0;
    std::cout << "Shortest time from the source:\n";
    
    for (int v = 0; v < V; v++) {
        total += time[v];
        std::cout << "City " << v << ": " << time[v] << "\n";
    }
    
    float average = total / 5.0;
    std::cout << "Average time: " << average << "\n";
}

int main() {
    std::vector<std::vector<int>> graph = {
        {0, 10, INFINITY, INFINITY, 15, 5},
        {10, 0, 10, 30, INFINITY, INFINITY},
        {INFINITY, 10, 0, 12, 5, INFINITY},
        {INFINITY, 30, 12, 0, INFINITY, 20},
        {15, INFINITY, 5, INFINITY, 0, INFINITY},
        {5, INFINITY, INFINITY, 20, INFINITY, 0}
    };

    int source;
    std::cout << "Enter the source city: ";
    std::cin >> source;

    dijkstraShortestPaths(graph, source);

    return 0;
}
