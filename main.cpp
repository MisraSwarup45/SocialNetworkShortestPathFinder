#include <iostream>
#include "graph.h"
using namespace std;

int main() {
    Graph socialNetwork;

    User user1(1, "Alice");
    User user2(2, "Bob");
    User user3(3, "Charlie");

    socialNetwork.addUser(user1);
    socialNetwork.addUser(user2);
    socialNetwork.addUser(user3);

    

    User user4(4, "David");
    User user5(5, "Eve");
    User user6(6, "Frank");

    

    socialNetwork.addUser(user4);
    socialNetwork.addUser(user5);
    socialNetwork.addUser(user6);

    socialNetwork.addConnection(1, 5, 5);
    socialNetwork.addConnection(1, 2, 1);
    socialNetwork.addConnection(2, 5, 1);
    socialNetwork.addConnection(4, 5, 4);
    socialNetwork.addConnection(5, 6, 6);

    int sourceId, targetId;
    cout << "Enter the IDs of the two users to find the shortest path between (separated by space):" << endl;
    cin >> sourceId >> targetId;

    vector<int> shortestPath = socialNetwork.shortestPath(sourceId, targetId);
    cout << "Shortest path between user " << sourceId << " and user " << targetId << ":";
    if (shortestPath.empty()) {
        cout << " No path exists." << endl;
    } else {
        for (int userId : shortestPath) {
            cout << " " << userId;
        }
        cout << endl;
    }

    return 0;
}
