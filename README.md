# taran4-mpara3-manasa3-anakind2
# Final Project


## [Video Presentation of Our Project](https://illinois.zoom.us/rec/play/OAFWXHu18PL73ML8iJlzTJVZ0MLFcK6fN20XttL-irCl-XgbM4ri0HhWzqKS9vuVX9R29bMUs0Wxbc_A.OOK8GRn7-vxTjNc_?startTime=1620874366000&_x_zm_rtaid=0jP6GesiRJ6rAaSGDbVq1A.1620873100573.2965a7a7305d0eef1dda061cc77d4ac1&_x_zm_rhtaid=435)

## Table of Contents 
- [Documentation](#documentation)
- [Installation](#installation)
- [Dataset](#dataset)
- [Building and Testing](#building)
- [Features](#features)

## Documentation
All documentation outlining our project development and results can be found in the [development](https://github-dev.cs.illinois.edu/cs225-sp21/taran4-mpara3-manasa3-anakind2/tree/master/development) folder

## Installation
To setup our project, clone the repository locally using the command
<br>
`` git clone https://github-dev.cs.illinois.edu/cs225-sp21/taran4-mpara3-manasa3-anakind2.git``
<br>
then ``cd`` to the directory in order to use the commands for executing our cases as covered in the next section

## Dataset
Our targetted dataset is the [Patent Citation Network](https://snap.stanford.edu/data/cit-Patents.html) which can be downloaded from the given link. The file can be placed in the ``tests`` folder and can assume the dataset has been included

## Building and Testing 
In order to run our tests suites, users must be running on EWS and execute the ``module load llvm/6.0.1`` command on their terminal then run ``make`` to compile. <br> 
Afterwards, execute ``make test && ./tests`` in order to run our test cases (our cases can be found [here](https://github-dev.cs.illinois.edu/cs225-sp21/taran4-mpara3-manasa3-anakind2/tree/master/tests))

To execute a sample of our dataset, run ``./main tests/simple_graph.txt 1``. (further tests can be found in ``main.cpp``) This command locates the graph data to use where 1 is the node in the graph data we want to use to generate the dijkstra's and betweenness data


## Features
* Our algorithms can be found in ``graph.cpp``
  * The algorithms we implemented were Dijkstras, BFS/Brandes Algorithms
* Used an istream operator to clean our data
* Wrote premade graphs to run our tests on single node, connected, and discontted
    * samples of our tests can be found in our ``tests`` folder and in ``main.cpp``
