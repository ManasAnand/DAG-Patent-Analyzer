# taran4-mpara3-manasa3-anakind2
# Final Project


## [Video Presentation of Our Project]()

## Table of Contents 
- [Documentation](#documentation)
- [Installation](#installation)
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

## Building and Testing
In order to run our tests suites, users must be running on EWS and execute the ``module load llvm/6.0.1`` command on their terminal then run ``make`` to compile. <br> 
Afterwards, execute ``make test && ./tests`` in order to run our test cases (our cases can be found [here](https://github-dev.cs.illinois.edu/cs225-sp21/taran4-mpara3-manasa3-anakind2/tree/master/tests) and ``./main`` executions in the ``main.cpp`` folder)


## Features
* Our algorithms can be found in ``graph.cpp``
  * The algorithms we implemented were Dijkstras, BFS/Brandes Algorithms
* Used an istream operator to clean our data
* Wrote premade graphs to run our tests on single node, connected, and discontted
    * samples of our tests can be found in our ``tests`` folder and in ``main.cpp``
