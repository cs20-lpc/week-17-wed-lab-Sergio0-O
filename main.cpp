// Implement main program.
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int INF = INT_MAX;

// Finds the unvisited vertex with the smallest distance
int getMinVertex(vector<int>& distance, vector<bool>& visited) {
    int minValue = INF;
    int minIndex = -1;

    for (int i = 0; i < distance.size(); i++) {
        if (!visited[i] && distance[i] < minValue) {
            minValue = distance[i];
            minIndex = i;
        }
    }

    return minIndex;
}

// Dijkstra's algorithm
void dijkstra(vector<vector<pair<int, int>>>& graph, int source) {

    int size = graph.size();

    // marking array
    vector<bool> visited(size, false);

    // distance array
    vector<int> distance(size, INF);

    // source distance is 0
    distance[source] = 0;

    // repeat V times
    for (int i = 0; i < size; i++) {

        // get unvisited vertex with minimum distance
        int current = getMinVertex(distance, visited);

        // stop early if no reachable vertex exists
        if (current == -1) {
            break;
        }

        // mark current vertex as visited
        visited[current] = true;

        // process all adjacent neighbors
        for (int j = 0; j < graph[current].size(); j++) {

            int neighbor = graph[current][j].first;
            int weight = graph[current][j].second;

            // compute possible new distance
            int newDistance = distance[current] + weight;

            // update minimum distance if smaller
            if (newDistance < distance[neighbor]) {
                distance[neighbor] = newDistance;
            }
        }
    }

    // print results
    cout << "Shortest distances from node "
         << source << ":" << endl;

    for (int i = 0; i < size; i++) {

        cout << "Node " << i << ": ";

        if (distance[i] == INF) {
            cout << "INF";
        }
        else {
            cout << distance[i];
        }

        cout << endl;
    }

    cout << endl;
}

int main() {

    // adjacency list graph
    vector<vector<pair<int, int>>> graph(6);

    // edges from node 0
    graph[0].push_back({1, 4});
    graph[0].push_back({2, 9});
    graph[0].push_back({4, 2});

    // edges from node 1
    graph[1].push_back({3, 1});
    graph[1].push_back({2, 2});

    // edges from node 2
    graph[2].push_back({3, 7});
    graph[2].push_back({5, 4});

    // edges from node 3
    graph[3].push_back({5, 1});

    // edges from node 4
    graph[4].push_back({2, 3});
    graph[4].push_back({5, 8});

    // run from source 0
    dijkstra(graph, 0);

    // run from source 1
    dijkstra(graph, 1);

    return 0;
}
