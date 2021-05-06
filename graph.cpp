#include <map>
#include <string>
#include <iostream>
#include <istream>
#include <sstream>
#include <fstream>
#include <vector>
#include <queue>

#include "graph.h"
using namespace std;

/**
*Constructor to initialize unordered map
*/
Graph::Graph() {
    adjList = map<Node, vector<Edge*>>();
}

/**
 * operator==
 */
bool Graph::operator==(const Graph & other) const {
    if (adjList.size() != other.adjList.size()) {
        cout << "different number of nodes" << endl;
        return false;
    }

    for (auto & otherPair : other.adjList) {
        //otherPair: {Node, vector<Edge>}

        //if node in other isn't in this, return false
        if (adjList.find(otherPair.first) == adjList.end()) {
            cout << "different nodes" << endl;
            return false;
        }

        //edge list corresponding to edge list in other
        auto & currentList = adjList.at(otherPair.first);

        // if different number of edges at that node, return false
        if (currentList.size() != otherPair.second.size()) { 
            cout << "different number of edges" << endl;
            return false;
        }

        for (size_t i = 0; i < currentList.size(); i++) {
            if (!(*currentList[i] == *otherPair.second[i])) {
                cout << "different edges at i" << endl;
                return false;
            }
        }
    }

    return true;
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
}

vector<int> Graph::incidentEdges(Node src) const {
    vector<Node> toReturn;
    vector<Edge*> toLoop = adjList.at(src);
    for (size_t i = 0; i < toLoop.size(); i++) {
        toReturn.push_back(toLoop[i] -> citee);
    }

    return toReturn;
}

bool Graph::areAdjacent(Node src, Node dest) {
    //.at throws exception if node(src) doesn't exist
    vector<Edge*> edgeList = adjList.at(src);
    for (auto e : edgeList) {
        if (e -> citee  == dest) {
            return true;
        }
    }

    return false;
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

void addEdgeFromLine(string current, Graph &graph) {
    string delimiter = " ";
    int from;
    int to;
    size_t pos;
    pos = current.find(delimiter);

    string temp = current.substr(0, pos);
    stringstream (temp) >> from;
    current.erase(0, pos + delimiter.length());
    temp = current;
    stringstream (temp) >> to;

    // add the patents as nodes here
    // convert the ints to Nodes
    // graph.insertEdge(node_from, node_to)

    graph.insertNode(from);
    graph.insertNode(to);

    graph.insertEdge(from, to);
}

istream &operator>>(istream  &input, Graph &graph) {
    string current;
    getline(input, current);
    while(current.at(0) == '#') {
        getline(input, current);
    }
    
    while(!input.eof()) {
        addEdgeFromLine(current, graph);
        getline(input, current);
    }
    addEdgeFromLine(current, graph);

    return input;
}

int Graph::getNumNodes() {
    return adjList.size();
}

// int Graph::getNumEdges() {
//     int count = 0;
//     for (auto pair: adjList) {
//         vector<int> current_edges = adjList(pair.first);
//         count += current_edges;
//     }

//     return count;
// }


/* Breadth First Search implementation
 * Heavily inspired by Brandes Algorithm for betweenness centrality
 * Takes in a starting node and returns a map of ending nodes and the shortest path of nodes from the start to the end
 */
map<int, vector<int> > Graph::breadthSearch(Node starting_point) {
    //map from node to nodes that lead to that node
    map<int, vector<int> > previous;
    map<int, vector<int> > paths;
    //map from node to distance from starting node. Unvisited / start node = -1. Adjacent node = 0 distance
    map<int, int> dist;
    for(auto node: adjList) {
        dist.insert({node.first, -1});
    }
    //map from end node to path from start node to that end node

    queue<Node> q;
    q.push(starting_point);
    dist[starting_point] = 0;
    while (!q.empty()) {
        Node current = q.front();
        q.pop();
        vector<Edge*>& adjs = adjList[current]; 

        for (auto edge: adjs) {
            Node connection = edge -> citee;
            
            if (dist[connection] == -1) {
                dist[connection] = dist[current] + 1;
                q.push(connection);
            } 
            if (dist[connection] == dist[current] + 1) {
                previous[connection].push_back(current);
            }
        }
    }

    // cout << "previous " << endl;
    // for(auto i: previous) {
    //     cout << i.first << ": ";
    //     // cout << i.second;
    //     for (auto j: i.second) {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
    for(auto node: dist) {
        //if node never visited or node is start, do nothing
    
        if (node.second == -1) {
            continue;
        }
        if (node.first == starting_point) {
            continue;
        }
        vector<int> toAdd;
        int currentNode = node.first;
        int currentDist = node.second;
        
        while (currentDist > 0) {
            vector<int> prevList = previous[currentNode];
            
            for (auto prevNode : prevList) {
                // cout << currentDist << endl;
                if (dist[prevNode] == currentDist - 1) {
                    toAdd.push_back(currentNode);
                    currentDist--;
                    currentNode = prevNode;
                }
            }
        }
        
        std::reverse(toAdd.begin(), toAdd.end());
        paths.insert({node.first, toAdd});
    }

    return paths;
}