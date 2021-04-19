#include <unordered_map>
#include <string>
#include <iostream>

#include "patent.h"
using namespace std;

/**
*Constructor to initialize unordered map
*/
Graph::Graph() {
    adjList = new unordered_map<Node*, vector<Edge*>>;
}

void Graph::insertNode(unsigned int id, string patent_inventor, unsigned int patent_year) {
    Node* node = new Node;
    node.patent = Patent(id, patent_inventor, patent_year);

    map.insert({node, vector<Edge*>(0)});
}

void Graph::insertEdge(Node* src, Node* dest) {
    Edge* edge = new Edge;
    edge.citer = src;
    edge.citee = dest;

    adjList.at(src).push_back(edge);
}