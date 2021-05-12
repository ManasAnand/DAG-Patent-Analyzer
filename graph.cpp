#include <map>
#include <string>
#include <iostream>
#include <istream>
#include <sstream>
#include <fstream>
#include <vector>
#include <queue>
#include <stack>
#include <random>
#include <limits>
#include <algorithm>


#include "graph.h"
using namespace std;

/**
*Constructor to initialize unordered map
*/
Graph::Graph() {
    adjList = map<Node, vector<Edge>>();
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
            Edge currentEdge = currentList[i];
            Edge otherEdge = otherPair.second[i];


            const bool otherInCurrent = (std::find(currentList.begin(), currentList.end(), otherEdge) != currentList.end());
            const bool currentInOther = (std::find(otherPair.second.begin(), otherPair.second.end(), currentEdge) != otherPair.second.end());
            if (!otherInCurrent || !currentInOther) {
                cout << "edge in one list isn't in the other" << endl;
                return false;
            }
        }
    }

    return true;
}

void Graph::insertNode(int id) {
    //note that if a node already exists nothing will change
    adjList.insert({id, vector<Edge>(0)});
}

void Graph::insertEdge(Node src, Node dest) {
    //TODO: Check if edge already exists or if node src doesn't exist

    //.at throws exception if node(src) doesn't exist
    vector<Edge> edgeList = adjList.at(src);
    for (auto e : edgeList) {
        if (e.citee  == dest) {
            return; //do nothing
        }
    }

    Edge edge;
    edge.citer = src;
    edge.citee = dest;
    edge.weight = 0 + (double)(rand()) / ((double)(1/(1 - 0)));

    adjList.at(src).push_back(edge);
}

vector<int> Graph::incidentEdges(Node src) const {
    vector<Node> toReturn;
    vector<Edge> toLoop = adjList.at(src);
    for (size_t i = 0; i < toLoop.size(); i++) {
        toReturn.push_back(toLoop[i].citee);
    }

    return toReturn;
}

bool Graph::areAdjacent(Node src, Node dest) {
    //.at throws exception if node(src) doesn't exist
    vector<Edge> edgeList = adjList.at(src);
    for (auto e : edgeList) {
        if (e.citee  == dest) {
            return true;
        }
    }

    return false;
}

Graph Graph::subgraph(Node start) {
    Graph g;

    if (adjList.find(start) == adjList.end()) {
        return g;
    }

    g.insertNode(start);
    queue<Node> q;
    q.push(start);
    while(!q.empty()) {
        Node current = q.front();
        q.pop();
        vector<Edge> edgeList = adjList.at(current);
        for (auto it = edgeList.begin(); it != edgeList.end(); ++it) {
            Node endpoint = (*it).citee;
            g.insertNode(endpoint);
            g.insertEdge(current, endpoint);
            q.push(endpoint);
        }
    }

    return g;
}

void Graph::printGraph() {
    for (auto it = adjList.begin(); it != adjList.end(); ++it) {
        cout << "Edges at node " << it -> first << endl;
        vector<Edge> toLoop = it -> second;
        for (size_t i = 0; i < toLoop.size(); i++) {
            cout << toLoop[i].citer << " ---> " << toLoop[i].citee << endl;
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

    graph.s.insert(to);
    graph.s.insert(from);
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
        vector<Edge>& adjs = adjList[current]; 

        for (auto edge: adjs) {
            Node connection = edge.citee;
            
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

void Graph::BFSBetweennessHelper(Node src, stack<int>& stack, map<Node, int>& sigma, map<int, vector<int>>& previous) {
    //map from node to distance from starting node. Unvisited / start node = -1. Adjacent node = 0 distance
    map<int, int> dist;
    for(auto node: adjList) {
        dist.insert({node.first, -1});
    }

    queue<Node> q;
    q.push(src);
    dist[src] = 0;
    while (!q.empty()) {
        Node current = q.front();
        stack.push(current);
        q.pop();
        vector<Edge>& adjs = adjList[current]; 

        for (auto edge: adjs) {
            Node connection = edge.citee;
            
            if (dist[connection] == -1) {
                dist[connection] = dist[current] + 1;
                q.push(connection);
            } 
            if (dist[connection] == dist[current] + 1) {
                previous[connection].push_back(current);
                sigma[connection] = sigma[connection] + sigma[current];
            }
        }
    }
}

//calculates the betweennessCentrality of every node in graph
//taken from https://www.cl.cam.ac.uk/teaching/1718/MLRD/handbook/brandes.html
map<int, double> Graph::betweennessCentrality() {
    map<Node, double> betweenness;
    map<Node, double> delta;
    map<int, vector<int>> previous;
    stack<Node> s;

    //for each node in the graph
    for (auto nodePair : adjList) {
        Node node = nodePair.first;

        //reset sigma, delta
        map<Node, int> sigma = { {node, 1} };
        delta.clear();
        previous.clear();
        

        //Step 2.2 BFSBetweennessHelper stuff
        BFSBetweennessHelper(node, s, sigma, previous);

        //Step 2.3 "While stack not empty"
        while (!s.empty()) {
            Node current = s.top();
            s.pop();

            for (vector<int>::const_iterator it = previous.at(current).begin(); it != previous.at(current).end(); ++it) {
                //previous.at(current) = vector<Node>
                int v = *it;
                delta[v] = delta[v] + ( ( double(sigma[v]) / double( sigma[current]) ) * (1 + delta[current]) );

                if (current != node) {
                    betweenness[current] = betweenness[current] + delta[current];
                }
            }
        }
    }

    return betweenness;
}

/**
map<int, double> Graph::dijkstraSearch(Node starting_point) {
    priority_queue<pair<int,int>, vector <pair<int, int>>, greater<pair<int, int>>>;
    double INF = std::numeric_limits<double>::infinity();
    map<int, double> dist;

    for (auto x: adjList) {
        dist[x.first] = INF;
    }

    pq.push(make_pair(0, starting_point));
    dist[starting_point] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
  
        // Get all adjacent of u. 
        for (auto y : adjList[u])
        {
            int v = y.first;
            int weight = y.second;
  
            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    return dist;
}
*/