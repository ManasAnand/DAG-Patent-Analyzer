#include <map>
#include <string>
#include <iostream>
#include <vector>

#include "graph.h"
using namespace std;

/**
*Constructor to initialize unordered map
*/
Graph::Graph() {
    adjList = map<Node, vector<Edge*>>();
}

void Graph::insertNode(int id) {
    //note that if a node already exists nothing will change
    adjList.insert({id, vector<Edge*>(0)});
}

void Graph::insertEdge(Node src, Node dest) {
    //TODO: Check if edge already exists or if node src doesn't exist

    //.at throws exception if node(src) doesn't exist
    vector<Edge*> edgeList = adjList.at(src);
    for (auto e : edgeList) {
        if (e -> citee  == dest) {
            return; //do nothing
        }
    }

    Edge* edge = new Edge;
    edge -> citer = src;
    edge -> citee = dest;

    adjList.at(src).push_back(edge);

    // cout << "testing edge added at src " << src << endl;
    
    // vector<Edge*> toLoop = adjList.at(src);
    // for (size_t i = 0; i < toLoop.size(); i++) {
    //     cout << src <<".citer = " << toLoop[i] -> citer << " and " << src << ".citee = " << toLoop[i] -> citee << endl;
    //     cout << endl;
    // }
}

vector<int> Graph::incidentEdges(Node src) const {
    vector<Node> toReturn;
    vector<Edge*> toLoop = adjList.at(src);
    for (size_t i = 0; i < toLoop.size(); i++) {
        toReturn.push_back(toLoop[i] -> citee);
    }

    return toReturn;
}

void Graph::printGraph() {
    for (auto it = adjList.begin(); it != adjList.end(); ++it) {
        cout << "Edges at node " << it -> first << endl;
        vector<Edge*> toLoop = it -> second;
        for (size_t i = 0; i < toLoop.size(); i++) {
            cout << toLoop[i]->citer << " ---> " << toLoop[i]->citee << endl;
            cout << endl;
        }
    }
}