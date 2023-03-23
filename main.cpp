//---------------------------------------------------------------------------
// lab3.cpp
//---------------------------------------------------------------------------
// This code tests the basic functionality of the classes to perform
// Dijkstra's algorihms and depth-first search for CSS 343 Lab 3.
// It is not meant to exhaustively test the classes.
//
// Assumptions:
//   -- students can follow the directions to interface with this file
//   -- text files "data31.txt" and "data32.txt" are formatted as described
//   -- Data file data3uwb provides an additional data set for part 1;
//      it must be edited, as it starts with a description how to use it
//---------------------------------------------------------------------------

/*
What to ask
- why the loop does not start again after 0 0 0
- why is it not working for data3uwb
- can i delete destructor???
- how to test it for other errors

*/

#include "graphl.h"
#include "graphm.h"
#include <fstream>
#include <iostream>
using namespace std;

int main() {
    // part 1
    ifstream infile1("data31.txt");
    if (!infile1) {
        cout << "File could not be opened." << endl;
        return 1;
    }

    // for each graph, find the shortest path from every node to all other
    // nodes
    for (;;) {
        GraphM G;
        G.buildGraph(infile1);
        if (infile1.eof())
            break;
        G.findShortestPath();
        G.displayAll();  // display shortest distance, path to cout
        G.display(3, 1); // display dist/path from node 3 to 1 to cout
                         // may be other calls to display
    }
    infile1.close();

    // part 2
    ifstream infile2("data32.txt");
    if (!infile2) {
        cout << "File could not be opened." << endl;
        return 1;
    }

    // for each graph, find the depth-first search ordering
    for (;;) {
        GraphL G;
        G.buildGraph(infile2);
        if (infile2.eof())
            break;
        G.displayGraph();
        G.depthFirstSearch(); // find and display depth-first ordering to cout
    }
    infile2.close();

    cout << endl;
    return 0;
}
