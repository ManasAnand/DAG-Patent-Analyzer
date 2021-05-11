#pragma once

#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>

using namespace std;

class Graph {
    private: 
        typedef int Node;

        struct Edge {
            //citer -> citee
            Node citer;
            Node citee;
            double weight;

            bool operator==(const Edge & other) {
                return (citer == other.citer) && (citee == other.citee);
            }
        };

        friend void addEdgeFromLine(string current, Graph &graph);

        void BFSBetweennessHelper(int src, stack<int>& stack, map<Node, int>& sigma, map<int, vector<int>>& previous);

        map<Node, vector<Edge*>> adjList;

    public:
        //construct Graph
        Graph();
        unordered_set<int> s;


        //rule of 3 UNCOMMENT IF NEEDED
        //Graph(const & Graph & other);
        //Graph & operator=(const Graph & other);
        //~Graph();
        //void _clear();

        bool operator==(const Graph & other) const;

        void DepthTraversal(int v);

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

        map<Node, vector<Node>> breadthSearch(Node starting_point);

        map<Node, double> betweennessCentrality();

        friend istream &operator>>( istream  &input, Graph &graph);


};