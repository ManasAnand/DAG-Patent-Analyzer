# Project Proposal

## Collaborative Distance in Patents

### Leading Question

In mathematics there is the notion of one's Erdős number. Paul Erdős was prolific mathematician who authored many papers and collaborated with hundreds of people. Someone's Erdős number is defined as the degree of separation via collaboration from Erdős. Erdős has number 0, his collaborators have number 1, and the pattern goes on. Other fields have similar numbers such as the Bacon number for acting and the Morphy number for chess. We hope to identify a suitable candidate in the field of patents to play the role of Erdős and then analyze the collaboration network and calculate the respective number between patent authors.

### Dataset Acquisition and Processing

The dataset we'll be using the Patent citation network from SNAP. This dataset contains data of all patents granted between January 1, 1963 to December 30, 1999. This graph is unweighted and directed and links patents via citations to other patents. We plan to complete all work on EWS machines and as such will download and include the data in our repository. As part of cleaning the data we will get rid of any nodes that are connected to 0 other nodes, if any such nodes exist.

### Graph Algorithms

In addition to some sort of traversal algorithm, the project will use Brandes' Algorithm for calculating betweenness centrality and Dijkstra's algorithm for finding the shortest path between nodes. For a traversal algorithm we will use a breadth first traversal which will be implemented in O(n) time. The rational for betweenness centrality is that this metric will identify candidates to use as the center of our collaborative distance. Since the graph is unweighted we can use Brandes' Algorithm which will be implemented in O(|V||E|) time. The algorithm uses a breadth first search and takes in nodes of a graph and calculates the betweenness centrality of each node in the graph and identifies the most central nodes in the graph. Then to find a given author's number we can call Dijkstra's algorithm on their patents and find the minimum shortest distance in O(|V|^2) time and this minimum will be the author's collaborative distance from the chosen center of the network. 

### Timeline

Data aquisition and processing should take 3-4 days. Then we hope to have the traversal fully completed by our mid-project check in. Then our graph algorithms should be implemented in under the following two weeks with our final deliverables completed a few days before the deadline in order to give time for making the presentation. Our deliverable will be an identification of the center of our graph and a way to calculate the collaboration distance between that center and a chosen author along with the path of citations along that way.  