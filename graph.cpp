#include "graph.h"
#include <queue>
#include <limits>
using namespace std;

void reverseVector(vector<int>& vec) {
    int left = 0;
    int right = vec.size() - 1;
    while (left < right) {
        swap(vec[left], vec[right]);
        left++;
        right--;
    }
}

Graph::Graph() {}

void Graph::addUser(const User& user) {
    users[user.getId()] = user;
}

void Graph::addConnection(int userId1, int userId2, int weight) {
    adjacencyList[userId1].push_back({userId2, weight});
    adjacencyList[userId2].push_back({userId1, weight});
}

vector<int> Graph::shortestPath(int sourceId, int targetId) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    unordered_map<int, int> dist;

    for (const auto& user : users) {
        dist[user.first] = numeric_limits<int>::max();
    }

    dist[sourceId] = 0;
    pq.push({0, sourceId});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (const auto& neighbor : adjacencyList[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    vector<int> path;
    int current = targetId;
    while (current != sourceId) {
        path.push_back(current);
        for (const auto& neighbor : adjacencyList[current]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            if (dist[current] == dist[v] + weight) {
                current = v;
                break;
            }
        }
    }
    path.push_back(sourceId);
    reverseVector(path);

    return path;
}
