#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../graph.h"

typedef int Node;

/**
 * Helper Functions as needed
 */

/**
 *Building graph from simple_graph.jpeg using normal constructor and insert functions
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

/**
 *Building graph from disconnected_graph.jpeg using normal constructor and insert functions
 */
Graph disconnectedFromConstructor() {
    Graph graph;
    for (int i = 1; i <= 9; i++) {
        graph.insertNode(i);
    }

    //first component
    graph.insertEdge(1, 2);
    graph.insertEdge(1, 4);
    graph.insertEdge(2, 3);
    graph.insertEdge(2, 5);
    graph.insertEdge(3, 5);

    //second component
    graph.insertEdge(6, 7);
    graph.insertEdge(6, 8);
    graph.insertEdge(6, 9);
    graph.insertEdge(7, 8);

    return graph;
}

/** 
 * Equality test cases
 */
TEST_CASE("Empty equality", "[unit_tests]") {
    Graph g1, g2;
    REQUIRE(g1 == g1);
    REQUIRE(g2 == g2);
    REQUIRE(g1 == g2);
    REQUIRE(g2 == g1);
}

TEST_CASE("Basic equality 1", "[unit_tests]") {
    Graph g1, g2;
    g1.insertNode(1);
    g1.insertNode(2);
    g1.insertEdge(1, 2);

    g2.insertNode(1);
    g2.insertNode(2);
    g2.insertEdge(1, 2);

    REQUIRE(g1 == g2);
    REQUIRE(g2 == g1);
}

TEST_CASE("Basic equality 2", "[unit_tests]") {
    Graph g1, g2;
    g1.insertNode(1);
    g1.insertNode(2);
    g1.insertEdge(1, 2);
    g1.insertEdge(1, 2);
    g1.insertEdge(1, 2);

    g2.insertNode(1);
    g2.insertNode(2);
    g2.insertEdge(1, 2);

    REQUIRE(g1 == g2);
    REQUIRE(g2 == g1);
}

TEST_CASE("Basic equality 3", "[unit_tests]") {
    Graph g1, g2;
    for (int i = 1; i <= 10; i++) {
        g1.insertNode(i);
    }

    for (int i = 1; i <= 10; i++) {
        g2.insertNode(i);
    }

    REQUIRE(g1 == g2);
    REQUIRE(g2 == g1);
}

TEST_CASE("Basic inequality 1", "[unit_tests]") {
    Graph g1, g2;
    g1.insertNode(1);
    g1.insertNode(2);
    g1.insertEdge(1, 2);

    g2.insertNode(1);
    g2.insertNode(2);
    g2.insertEdge(1, 2);
    g2.insertEdge(2, 1);

    REQUIRE(!(g1 == g2));
    REQUIRE(!(g2 == g1));
}

TEST_CASE("Basic inequality 2", "[unit_tests]") {
    Graph g1, g2;
    g1.insertNode(1);
    g1.insertNode(2);
    g1.insertNode(3);
    g1.insertEdge(1, 2);

    g2.insertNode(1);
    g2.insertNode(2);
    g2.insertEdge(1, 2);

    REQUIRE(!(g1 == g2));
    REQUIRE(!(g2 == g1));
}

TEST_CASE("Basic inequality 3", "[unit_tests]") {
    Graph g1, g2;
    for (int i = 1; i <= 10; i++) {
        g1.insertNode(i);
    }

    for (int i = 1; i <= 9; i++) {
        g2.insertNode(i);
    }

    REQUIRE(!(g1 == g2));
    REQUIRE(!(g2 == g1));
}

/** 
 * Testing that building graph from file vs from manually inserting nodes/edges works and is consistent
 */
TEST_CASE("simple_graph constructor equality", "[unit_tests]") {
    Graph g1 = simpleFromConstructor();
    
    Graph g2;
    ifstream file("tests/simple_graph.txt");
    file >> g2;

    REQUIRE(g1 == g2);
    REQUIRE(g2 == g1);
}

TEST_CASE("simple_graph constructor inequality", "[unit_tests]") {
    Graph g1 = simpleFromConstructor();
    g1.insertNode(11);
    g1.insertEdge(10, 11);
    
    Graph g2;
    ifstream file("tests/simple_graph.txt");
    file >> g2;

    REQUIRE(!(g1 == g2));
    REQUIRE(!(g2 == g1));
}

TEST_CASE("disconnected_graph constructor equality", "[unit_tests]") {
    Graph g1 = disconnectedFromConstructor();
    
    Graph g2;
    ifstream file("tests/disconnected_graph.txt");
    file >> g2;

    REQUIRE(g1 == g2);
    REQUIRE(g2 == g1);
}

TEST_CASE("disconnected_graph constructor inequality", "[unit_tests]") {
    Graph g1 = disconnectedFromConstructor();
    g1.insertNode(10);
    g1.insertEdge(9, 10);
    
    Graph g2;
    ifstream file("tests/disconnected_graph.txt");
    file >> g2;

    REQUIRE(!(g1 == g2));
    REQUIRE(!(g2 == g1));
}

// TEST_CASE("Test Traversal", "[bfs]") {
//     Graph g;
//     g.insertNode(1);
//     g.insertNode(2);
//     g.insertNode(3);
//     g.insertNode(4);

//     g.insertEdge(1,2);
//     g.insertEdge(2,4);
//     g.insertEdge(1,3);

//     map<int, vector<int>> traversal = g.breadthSearch(1);
//     map<int, vector<int>> expected; 
// }

TEST_CASE("Simple Traversal", "[bfs]") {
    Graph g = simpleFromConstructor();

    map<int, vector<int>> traversal = g.breadthSearch(1);

    vector<int> oneToFive{ 5 };
    REQUIRE(traversal.at(5) == oneToFive);

    vector<int> oneToTen{ 2, 3, 10 };
    REQUIRE(traversal.at(10) == oneToTen);

    REQUIRE(traversal.find(8) == traversal.end());
    REQUIRE(traversal.find(9) == traversal.end());
    REQUIRE(traversal.find(1) == traversal.end());
}

TEST_CASE("Empty subgraph", "[subgraph]") {
    Graph g;
    g.insertNode(1);
    g.insertNode(2);
    g.insertEdge(1, 2);

    Graph subgraph = g.subgraph(3);

    Graph empty;

    REQUIRE(subgraph == empty);
    REQUIRE(empty == subgraph);
}

TEST_CASE("Basic subgraph", "[subgraph]") {
    Graph g;
    g.insertNode(1);
    g.insertNode(2);
    g.insertEdge(1, 2);

    Graph subgraph = g.subgraph(1);

    REQUIRE(g == subgraph);
    REQUIRE(subgraph == g);

    Graph otherSubgraph = g.subgraph(2);

    Graph justTwo;
    justTwo.insertNode(2);

    REQUIRE(otherSubgraph == justTwo);
    REQUIRE(justTwo == otherSubgraph);
}

TEST_CASE("Simple subgraph 1", "[subgraph]") {
    Graph g = simpleFromConstructor();

    Graph subgraph = g.subgraph(1);

    Graph expected;
    expected.insertNode(1);
    expected.insertNode(2);
    expected.insertNode(3);
    expected.insertNode(4);
    expected.insertNode(5);
    expected.insertNode(6);
    expected.insertNode(7);
    expected.insertNode(10);
    expected.insertEdge(1, 2);
    expected.insertEdge(1, 5);
    expected.insertEdge(2, 3);
    expected.insertEdge(2, 4);
    expected.insertEdge(2, 6);
    expected.insertEdge(3, 4);
    expected.insertEdge(3, 5);
    expected.insertEdge(3, 10);
    expected.insertEdge(4, 7);
    expected.insertEdge(5, 7);
    expected.insertEdge(6, 4);
    expected.insertEdge(6, 7);
    expected.insertEdge(7, 10);
    
    //sanity checks
    REQUIRE(!(g == expected));
    REQUIRE(!(expected == g));
    REQUIRE(!(g == subgraph));
    REQUIRE(!(subgraph == g));

    REQUIRE(subgraph == expected);
    REQUIRE(expected == subgraph);
}

TEST_CASE("Disconnected Subgraph 1", "[subgraph]") {
    Graph g = disconnectedFromConstructor();

    Graph subgraph = g.subgraph(1);

    Graph expected;
    expected.insertNode(1);
    expected.insertNode(2);
    expected.insertNode(3);
    expected.insertNode(4);
    expected.insertNode(5);
    expected.insertEdge(1, 2);
    expected.insertEdge(1, 4);
    expected.insertEdge(2, 3);
    expected.insertEdge(2, 5);
    expected.insertEdge(3, 5);

    //sanity checks
    REQUIRE(!(g == expected));
    REQUIRE(!(expected == g));
    REQUIRE(!(g == subgraph));
    REQUIRE(!(subgraph == g));

    REQUIRE(subgraph == expected);
    REQUIRE(expected == subgraph);
}

TEST_CASE("Disconnected Subgraph 2", "[subgraph]") {
    Graph g = disconnectedFromConstructor();

    Graph subgraph = g.subgraph(6);

    Graph expected;
    expected.insertNode(6);
    expected.insertNode(7);
    expected.insertNode(8);
    expected.insertNode(9);
    expected.insertEdge(6, 7);
    expected.insertEdge(6, 8);
    expected.insertEdge(6, 9);
    expected.insertEdge(7, 8);
    
    //sanity checks
    REQUIRE(!(g == expected));
    REQUIRE(!(expected == g));
    REQUIRE(!(g == subgraph));
    REQUIRE(!(subgraph == g));

    REQUIRE(subgraph == expected);
    REQUIRE(expected == subgraph);
}