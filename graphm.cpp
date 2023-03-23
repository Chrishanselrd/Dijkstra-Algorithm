#include "graphm.h"
#include <algorithm>
#include <climits>
#include <iomanip>
#include <string>

//----------------------------------------------------------------------------
// default constructor
// Constructs a Graph
GraphM::GraphM() {
    size = 0;
    for (int i = 0; i < MAXNODES; i++) {
        for (int j = 0; j < MAXNODES; j++) {
            C[i][j] = INT_MAX;
            T[i][j].visited = false;
            T[i][j].dist = INT_MAX;
            T[i][j].path = 0;
        }
    }
}

//----------------------------------------------------------------------------
// buildGraph()
// Constructs a Graph from a data text file
void GraphM::buildGraph(istream &inFile) {
    string line;

    // inserting size
    inFile >> size;
    if (inFile.eof())
        return;

    getline(inFile, line);
    // inserting the name to NodeData
    for (int i = 1; i <= size; i++) {
        data[i].setData(inFile);
    }

    int start, end, value;
    while (inFile >> start >> end >> value) {
        // if input is invalid or stopped
        if (start < 0 || end < 0 || value < 0) {
            break;
        } else if (start == 0 && end == 0 && value == 0) {
            return;
        }

        // inserts to cost matrix
        insertEdge(start, end, value);
    }
}

//----------------------------------------------------------------------------
// insertEdge
// inserts an edge to the cost matrix
void GraphM::insertEdge(int start, int end, int value) {
    if (start, end >= 0 && start, end <= size) {
        C[start][end] = value;
    }
}

//----------------------------------------------------------------------------
// removeEdge
// removes an edge from the cost matrix = sets it to infinity
void GraphM::removeEdge(int start, int end) {
    if (start, end >= 0 && start, end <= size) {
        C[start][end] = INT_MAX;
    }
}

//----------------------------------------------------------------------------
// findShortestPath
// implements the Dijkstra algortihm to find the shortest path for each source
void GraphM::findShortestPath() {
    int minDist = INT_MAX;
    int v = 0;

    // determining the source
    for (int source = 1; source <= size; source++) {

        // sets source to 0
        T[source][source].dist = 0;

        // comparing dist
        for (int k = 1; k <= size - 1; k++) {

            // find v
            minDist = INT_MAX;
            for (int i = 1; i <= size; i++) {
                if (T[source][i].dist < minDist && !T[source][i].visited) {
                    minDist = T[source][i].dist;
                    v = i;
                }
            }
            T[source][v].visited = true;

            // operation
            for (int w = 1; w <= size; w++) {
                if (C[v][w] != INT_MAX && !T[source][w].visited) {
                    if (T[source][v].dist + C[v][w] < T[source][w].dist) {
                        T[source][w].dist = T[source][v].dist + C[v][w];
                        T[source][w].path = v;
                    }
                }
            }
        }
    }
}

//----------------------------------------------------------------------------
// displayAll
// Displays all of the data name, starting node, end node, cost, and the
// shortest path
void GraphM::displayAll() const {
    cout << "Description               From node  To node  Dijkstra's  Path"
         << endl;
    for (int i = 1; i <= size; i++) {
        cout << data[i] << endl;
        for (int j = 1; j <= size; j++) {

            if (j != i) {
                cout << setw(32) << i << setw(10) << j << setw(10);
                if (T[i][j].dist == INT_MAX) {
                    cout << "---" << endl;
                } else {
                    cout << T[i][j].dist << setw(8);
                    displayPath(i, j);
                    cout << " " << endl;
                }
            }
        }
    }
}

//----------------------------------------------------------------------------
// displayPath
// a recursive funtion to display the shortest path
void GraphM::displayPath(int start, int end) const {
    if (start == end) {
        cout << start << " ";
    } else {
        displayPath(start, T[start][end].path);
        cout << end << " ";
    }
}

//----------------------------------------------------------------------------
// display
// displays the starting node, end node, the cost, and shortest path
void GraphM::display(int start, int end) const {
    cout << setw(8) << start << setw(8) << end << setw(8);
    if (T[start][end].dist == INT_MAX) {
        cout << "---" << endl;
    } else {
        cout << T[start][end].dist << setw(8);
        displayPath(start, end);
        cout << " " << endl;
    }
}
