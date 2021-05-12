#include <string>
#include <iostream>
#include <istream>
#include <fstream>
#include "graph.h"

using namespace std;

int main() {
    Graph g;

    ifstream file("data/cit-Patents.txt");
    file >> g;
    cout << g.s.size() << endl;

    return 0;
}