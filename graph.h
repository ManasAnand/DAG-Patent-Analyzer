#pragma once

#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;

class Graph {
    private: 
        struct Node {
            unsigned int patent_id;
            string inventor;
            unsigned int year;

        };

        struct Edge {
            //citer -> citee
            Node* citer;
            Node* citee;
        };

        unordered_map<Node*, vector<Edge*>> map;

    public:
        //construct Graph
        Graph();

        //insertVertex
        void insertNode(unsigned int id, string patent_inventor, unsigned int patent_year);

        //insertEdge
        void insertEdge(Node* src, Node* dest);

        //incidentEdges
        vector<Edge*> incidentEdges(Node* input);

        //areAdjacent
        bool areAdjacent(Node* src, Node* dest);

};