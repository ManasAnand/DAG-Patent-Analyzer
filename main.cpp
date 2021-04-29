#include <string>
#include <iostream>
#include <istream>
#include <fstream>
#include "graph.h"

using namespace std;

int main() {
    Graph g;

    ifstream file("data/cit-Patents.txt");
    file >> g;
    cout << g.GetGraph().size() << endl;
    // g.insertNode(1);
    // g.insertNode(2);
    // g.insertEdge(1, 2);
    // g.insertNode(3);
    // g.insertEdge(1, 3);
    // g.insertNode(4);
    // g.insertEdge(1, 4);

    // g.insertEdge(3, 4);
    // g.insertEdge(2, 3);
    // g.insertEdge(4, 3);
    // g.insertEdge(3, 4);

    // g.insertNode(1);
    // g.insertEdge(1, 5);

    // g.printGraph();

    // cout << "incident edges of 1 are:" << endl;
    // vector<int> incid = g.incidentEdges(1);
    // for (size_t i = 0; i < incid.size(); i++) {
    //     cout << incid[i] << endl;
    // }

    // if (g.areAdjacent(2, 3)) {
    //     cout << "2 and 3 are adjacent" << endl;
    // } else {
    //     cout << "2 and 3 are not adjacent" << endl;
    // }

    // if (g.areAdjacent(3, 2)) {
    //     cout << "3 and 2 are adjacent" << endl;
    // } else {
    //     cout << "3 and 2 are not adjacent" << endl;
    // }

    return 0;
}