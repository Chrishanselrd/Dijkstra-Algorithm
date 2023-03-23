#include "graphl.h"
#include <iomanip>
#include <string>

//----------------------------------------------------------------------------
// default constructor
// Constructs an array of lists
GraphL::GraphL() {
    for (int i = 0; i < MAX_NODES; i++) {
        nodes[i].data = NodeData();
    }
    size = 0;
}

//----------------------------------------------------------------------------
// destructor
// not used because the data used is NodeData and not a pointer
GraphL::~GraphL() {}

//----------------------------------------------------------------------------
// buildGraph
// inserts data to the array of list from a data text
void GraphL::buildGraph(ifstream &inFile) {
    string line;

    inFile >> size;
    if (inFile.eof())
        return;

    getline(inFile, line);
    for (int i = 1; i <= size; i++) {
        nodes[i].data.setData(inFile);
        nodes[i].visited = false;
    }

    int start, end;
    while (inFile >> start >> end) {
        if (start, end < 0) {
            break;
        } else if (start, end == 0) {
            return;
        }

        nodes[start].edges.push_back(end);
    }
}

//----------------------------------------------------------------------------
// displayGraph
// Displays the node, node name, and the edges
void GraphL::displayGraph() const {
    cout << "Graph:" << endl;
    for (int i = 1; i <= size; i++) {
        cout << "Node " << i << setw(30) << nodes[i].data << endl;
        for (int j : nodes[i].edges) {
            cout << setw(10) << "edges " << i << " " << j << endl;
        }
    }
}

//----------------------------------------------------------------------------
// depthFirstSearch
// displays the depth first search order
void GraphL::depthFirstSearch() {
    cout << "Depth-first ordering: ";
    for (int i = 1; i <= size; i++) {
        if (!nodes[i].visited) {
            depthFirstSearchHelper(i);
        }
    }
    cout << endl;
}

//----------------------------------------------------------------------------
// depthFirstSearchHelper
// a helper function to print out the depth first search order
void GraphL::depthFirstSearchHelper(int num) {
    nodes[num].visited = true;

    cout << num << " ";
    for (int x : nodes[num].edges) {
        if (!nodes[x].visited) {
            depthFirstSearchHelper(x);
        }
    }
}