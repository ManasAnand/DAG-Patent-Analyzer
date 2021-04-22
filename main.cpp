#include <string>
#include <iostream>

#include "graph.h"

using namespace std;

int main() {
    Graph g;

    g.insertNode(1);
    g.insertNode(2);
    g.insertEdge(1, 2);
    g.insertNode(3);
    g.insertEdge(1, 3);
    g.insertNode(4);
    g.insertEdge(1, 4);

    g.insertEdge(3, 4);
    g.insertEdge(2, 3);
    g.insertEdge(4, 3);
    g.insertEdge(3, 4);

    g.insertNode(1);
    g.insertEdge(1, 5);

    g.insertEdge(9999, 1);

    g.printGraph();

    cout << "incident edges of 1 are:" << endl;
    vector<int> incid = g.incidentEdges(1);
    for (size_t i = 0; i < incid.size(); i++) {
        cout << incid[i] << endl;
    }
    return 0;
}