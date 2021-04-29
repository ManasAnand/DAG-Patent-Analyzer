#pragma once

#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph {
    private: 
        typedef int Node;

        struct Edge {
            //citer -> citee
            Node citer;
            Node citee;
        };

        void DepthTraversal(int v);
        map<Node, vector<Edge*>> adjList;
        map<int, bool> alr_visited;

    public:
        //construct Graph
        Graph();

        //insertVertex
        void insertNode(int id);

        //insertEdge
        void insertEdge(Node src, Node dest);

        //incidentEdges
        vector<Node> incidentEdges(Node src) const;

        //areAdjacent
        bool areAdjacent(Node src, Node dest);

        void printGraph();

        int getNumNodes();
        int getNumEdges();

        void DepthTraversal();
        map<Node, vector<Edge*>> breadthTraversal(Node starting_point);

        friend istream &operator>>( istream  &input, Graph &graph);
};