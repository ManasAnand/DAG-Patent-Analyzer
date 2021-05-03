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

istream &operator>>(istream  &input, Graph &graph) {
    string current;
    getline(input, current);
    while(current.at(0) == '#') {
        getline(input, current);
    }
    string delimiter = " ";
    
    while(!input.eof()) {
        int from;
        int to;

        string line;
        getline(input, line);
        size_t pos;
        pos = line.find(delimiter);

        string temp = line.substr(0, pos);
        stringstream (temp) >> from;
        line.erase(0, pos + delimiter.length());
        temp = line;
        stringstream (temp) >> to;

        // add the patents as nodes here
        // convert the ints to Nodes
        // graph.insertEdge(node_from, node_to)

        graph.insertNode(from);
        graph.insertNode(to);

        graph.insertEdge(from, to);
    }
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

void Graph::DepthTraversal() {
    for (auto i: adjList) {
        if (!alr_visited[i.first]) {
            DepthTraversal(i.first);
        }
    }
}

void Graph::DepthTraversal(int node_val) {
    alr_visited[node_val] = true;
    cout << node_val << " ";

    for (auto i: adjList[node_val]) {
        if (!alr_visited[i->citee]) {
            DepthTraversal(i->citee);
        }
    }

}


/* Breadth First Search implementation
 * Heavily inspired by Brandes Algorithm for betweenness centrality
 * Takes in a starting node and returns a map of ending nodes and the shortest path of nodes from the start to the end
 */
map<int, vector<int>> Graph::breadthSearch(Node starting_point) {
    //map from node to nodes that lead to that node
    map<int, vector<int>> previous;
    //map from node to distance from starting node. Unvisited / start node = -1. Adjacent node = 0 distance
    map<int, int> dist;
    for(auto node: adjList) {
        dist.insert({node.first, -1});
    }
    //map from end node to path from start node to that end node
    map<int, vector<int>> paths;
    
    queue<Node> q;
    q.push(starting_point);
    while (!q.empty()) {
        Node current = q.front();
        q.pop();
        vector<Edge*>& adjs = adjList[current]; 

        for (auto edge: adjs) {
            Node connection = edge -> citee;
            if (dist[connection] == -1) {
                dist[connection] = dist[current] + 1;
                q.push(connection);
            } else if (dist[connection] == dist[current] + 1) {
                previous[connection].push_back(current);
            }
        }
    }

    for(auto node: dist) {
        //if node never visited or node is start, do nothing
        if (node.second == -1) {
            continue;
        }
        vector<int> toAdd;
        Node currentNode(node.first);
        int currentDist = node.second;
        while (currentDist > -1) {
            vector<int>& prevList = previous.at(currentNode);
            for (auto & prevNode : prevList) {
                if (dist[prevNode] == currentDist - 1) {
                    toAdd.push_back(currentNode);
                    currentDist--;
                    currentNode = prevNode;
                }
            }
        }
        paths.insert({node.first, toAdd});
    }

    return paths;
}