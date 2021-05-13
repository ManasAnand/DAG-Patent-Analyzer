# RESULTS
## I. Outcomes
Overall, our team was able to meet the goals we set fourth earlier in the project. We were able to implement the algorithms we wanted to, as our Breadth Traversal and Dijkstra’s Algorithm are able to recognize the different paths in the graph.

## II. Discoveries
The program traverses through the dataset and creates a subgraph that starts at the user-specified patent number. It returns the betweenness centrality of each node of the subgraph as well as the lowest weighted path.

We have an extremely large dataset and a limited amount of computational power, so we were unable to find the results for our actual dataset. However, we recreated a section of the data in a smaller file and received the following results:

``
The Betweenness Centrality at every node in generated subgraph is
1: 0
2: 3.5
3: 2.5
4: 1
5: 2
6: 0.5
7: 3.5
10: 0
The sum of weights from 1 to every other node is
1: 0
2: 5.07717
3: 12.2615
4: 7.11743
5: 9.13233
6: 6.93003
7: 12.1222
``
