#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
    // Priority queue to store {distance, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    // Distance vector initialized to infinity
    vector<int> dist(V, INT_MAX);
    dist[S] = 0; // Distance to source is 0

    // Push the source with distance 0
    pq.push({0, S});
    
    // Dijkstra's algorithm
    while (!pq.empty()) {
        int dis = pq.top().first;  // Current distance
        int node = pq.top().second; // Current node
        pq.pop();

        // Iterate over all adjacent nodes
        for (auto it : adj[node]) {
            int adjnode = it[0];  // Adjacent node
            int weight = it[1];   // Weight of the edge

            // Relax the edge if a shorter path is found
            if (dist[node] + weight < dist[adjnode]) {
                dist[adjnode] = dist[node] + weight;
                pq.push({dist[adjnode], adjnode});
            }
        }
    }
    
    return dist;
}

int main() {
    int V = 4;
    
    // Adjacency list representation of the graph
    vector<vector<int>> adj[V];
    
    adj[0].push_back({1, 1});
    adj[0].push_back({2, 4});
    adj[1].push_back({0, 1});
    adj[1].push_back({2, 2});
    adj[1].push_back({3, 5});
    adj[2].push_back({0, 4});
    adj[2].push_back({1, 2});
    adj[2].push_back({3, 1});
    adj[3].push_back({1, 5});
    adj[3].push_back({2, 1});
    
    int S = 0;
    
     // Run Dijkstra for every node to simulate Link State Routing
    vector<vector<int>> routing_table(V, vector<int>(V, INT_MAX)); // Routing table
    
    for (int i = 0; i < V; i++) {
        // Compute shortest distances from node i to all other nodes
        vector<int> shortest_dist = dijkstra(V, adj, i);
        
        // Store the distances in the routing table
        for (int j = 0; j < V; j++) {
            routing_table[i][j] = shortest_dist[j];
        }
    }

    // Display the routing table (Shortest paths from each node to every other node)
    cout << "Link State Routing Table (Shortest paths from each node):\n";
    for (int i = 0; i < V; i++) {
        cout << "From Node " << i << ":\n";
        for (int j = 0; j < V; j++) {
            if (routing_table[i][j] == INT_MAX) {
                cout << "  To Node " << j << ": No path\n";
            } else {
                cout << "  To Node " << j << ": " << routing_table[i][j] << "\n";
            }
        }
        cout << endl;
    }


    
    
    return 0;
}

