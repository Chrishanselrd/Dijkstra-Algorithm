#ifndef GRAPHL_H
#define GRAPHL_H

#include "nodedata.h"
#include <list>
#include <string>

using namespace std;

//---------------------------------------------------------------------------
// GraphL:  GraphL object creates a graph that hold the edges between nodes.
//          It stores the data in an array of lists. It implements the
//          depth first search algorithm
//
// Implementation and assumptions:
//   -- the number of nodes is nonnegative integer
//   -- the decription of the node has 50 char max
//   -- The data is correctly formatted
//   -- 0 0 stops the buildGraph function
//   -- must handle graph with disconnected components

const int MAX_NODES = 100;

class GraphL {
  public:
    // constructor and destructor
    GraphL();
    ~GraphL();

    // builds graph
    void buildGraph(ifstream &inFile);

    // displays graph and Depth for search order
    void displayGraph() const;
    void depthFirstSearch();
    void depthFirstSearchHelper(int num);

  private:
    struct GraphNode {
        list<int> edges;
        NodeData data;
        bool visited;
    };

    GraphNode nodes[MAX_NODES];
    int size;
};

#endif
