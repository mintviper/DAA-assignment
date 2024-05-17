#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

#define INF INT_MAX


struct Edge {
    int destination;
    int weight;
};


void dijkstra(vector<vector<Edge>>& graph, int start, vector<int>& distances, vector<int>& prev) {
    int V = graph.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    distances.assign(V, INF);
    prev.assign(V, -1);

    distances[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        int dist_u = pq.top().first;
        pq.pop();

        if (dist_u > distances[u])
            continue;

        for (const Edge& e : graph[u]) {
            int v = e.destination;
            int weight = e.weight;

            if (distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                prev[v] = u;
                pq.push({distances[v], v});
            }
        }
    }
}

void printShortestPath(int start, const vector<int>& distances, const vector<int>& prev) {
    cout << "Shortest path and distance from Friend " << start << " to Akshay's house:\n";
    for (int i = 0; i < distances.size(); ++i) {
        cout << "Distance to node " << i << ": " << distances[i] << ", Path: ";
        vector<int> path;
        for (int v = i; v != -1; v = prev[v])
            path.push_back(v);
        for (int j = path.size() - 1; j >= 0; --j)
            cout << path[j] << " ";
        cout << endl;
    }
}

int main() {
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<Edge>> graph(V);
    cout << "Enter the edges (source, destination, weight):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        // graph[v].push_back({u, w}); // for undirected graph
    }

   
    int akshay_house = 0;


    for (int i = 1; i < V; ++i) {
        vector<int> distances, prev;
        dijkstra(graph, i, distances, prev);
        printShortestPath(i, distances, prev);
    }

    return 0;
}
