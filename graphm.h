#ifndef GRAPHM_H
#define GRAPHM_H

#include "nodedata.h"
#include <climits>
#include <fstream>
#include <iostream>

using namespace std;

//---------------------------------------------------------------------------
// GraphM:  GraphM object creates a graph that implements the Dijkstra's
//          algorithm to find the shortest path between nodes. It consist
//          of cost matrix, data for graph nodes information, size, and
//          a graph for the algorithm.
//
// Implementation and assumptions:
//   -- the graph is type TableType that has variables visited, distance,
//      and path
//   -- the number of nodes is nonnegative integer
//   -- the decription of the node has 50 char max
//   -- The data is correctly formatted
//   -- 0 0 0 stops the buildGraph function

const int MAXNODES = 100;

class GraphM {
  public:
    // constructor
    GraphM();

    // graph functions
    void buildGraph(istream &inFile);
    void insertEdge(int start, int end, int value);
    void removeEdge(int start, int end);
    void findShortestPath();

    // display functions
    void displayAll() const;
    void displayPath(int start, int end) const;
    void display(int start, int end) const;

  private:
    struct TableType {
        bool visited;
        int dist;
        int path;
    };

    NodeData data[MAXNODES];         // data for graph nodes information
    int C[MAXNODES][MAXNODES];       // Cost array, the adjacency matrix
    int size;                        // number of nodes in the graph
    TableType T[MAXNODES][MAXNODES]; // stores Dijkstra information
};

#endif
