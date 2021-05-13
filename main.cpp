#include <string>
#include <iostream>
#include <istream>
#include <fstream>
#include <sstream>
#include "graph.h"

typedef int Node;

using namespace std;

// ./main  file_location  patent_number
//   [0]        [1]            [2]
int main(int argc, const char** argv) {
    Graph g;

    string file_location = argv[1];
    ifstream file(file_location);
    file >> g;
    
    stringstream stream(argv[2]);
    int starting_node;
    stream >> starting_node;

    Graph subgraph = g.subgraph(starting_node);

    if (subgraph.getNumNodes() == 0) {
        cout << "starting node is not valid" << endl;
        return 0;
    }

    map<Node, double> betweenness = subgraph.betweennessCentrality();

    cout << "The Betweenness Centrality at every node in generated subgraph is" << endl;

    for (auto const & x : betweenness) {
        cout << x.first << ": " << betweenness.at(x.first) << endl;
    }

    map<int, double> dijkstra = subgraph.dijkstraSearch(starting_node);

    cout << "The sum of weights from " << starting_node << " to every other node is" << endl;

    for (auto const & x : dijkstra ) {
        cout << x.first << ": " << dijkstra .at(x.first) << endl;
    }

    return 0;
}