#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../graph.h"

typedef int Node;

/**
 * Helper Functions as needed
 */

/**
 *Building graph from simple_graph.jpg using normal constructor and insert functions
 */
Graph simpleFromConstructor() {
    Graph graph;
    for (int i = 1; i <= 10; i++) {
        graph.insertNode(i);
    }
    graph.insertEdge(1, 2);
    graph.insertEdge(1, 5);
    graph.insertEdge(2, 3);
    graph.insertEdge(2, 4);
    graph.insertEdge(2, 6);
    graph.insertEdge(3, 4);
    graph.insertEdge(3, 5);
    graph.insertEdge(3, 10);
    graph.insertEdge(4, 7);
    graph.insertEdge(5, 7);
    graph.insertEdge(6, 4);
    graph.insertEdge(6, 7);
    graph.insertEdge(7, 10);
    graph.insertEdge(8, 5);
    graph.insertEdge(8, 7);
    graph.insertEdge(9, 6);

    return graph;
}

TEST_CASE("Simple inequality", "[ruleOf3]") {
    Graph g1, g2;
    g1.insertNode(1);
    g1.insertNode(2);
    g1.insertEdge(1, 2);

    g2.insertNode(1);
    g2.insertNode(2);
    g2.insertEdge(1, 2);
    g2.insertEdge(2, 1);

    REQUIRE(!(g1 == g2));
}