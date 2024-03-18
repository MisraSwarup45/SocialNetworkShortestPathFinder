#ifndef GRAPH_H
#define GRAPH_H

#include "user.h"
#include <unordered_map>
#include <vector>
using namespace std;

class Graph {
private:
    unordered_map<int, User> users;
    unordered_map<int, vector<pair<int, int>>> adjacencyList;

public:
    Graph();
    void addUser(const User& user);
    void addConnection(int userId1, int userId2, int weight);
    vector<int> shortestPath(int sourceId, int targetId);
};

#endif
