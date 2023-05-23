#include <cstring>
#include <iostream>
using namespace std;

#define INF 9999999

// number of vertices in graph
#define V 6

// create a 2d array of size 6x6
// for adjacency matrix to represent the graph

int G[V][V] = {
  {0, 3, 0, 0, 0, 1},
  {3, 0, 2, 1, 10, 0},
  {0, 2, 0, 3, 0, 5},
  {0, 1, 3, 0, 5, 0},
  {0, 10, 0, 5, 0, 4},
  {1, 0, 5, 0, 4, 0}
};

int main() {
  int no_edge;  // number of edges

  // create an array to track selected vertices
  // selected will become true if the vertex is selected, otherwise false
  int selected[V];

  // set selected to false initially
  memset(selected, false, sizeof(selected));

  // set the number of edges to 0
  no_edge = 0;

  // the number of edges in the minimum spanning tree will always be
  // less than (V - 1), where V is the number of vertices in the graph

  // choose the 0th vertex and mark it as selected
  selected[0] = true;

  int x;  // row number
  int y;  // column number

  // print the selected edges and their weights
  cout << "Edge"
       << " : "
       << "Weight";
  cout << endl;
  while (no_edge < V - 1) {
    // For every vertex in the selected set, find all adjacent vertices,
    // calculate the distance from the vertex selected at the previous step.
    // If the vertex is already in the selected set, discard it. Otherwise,
    // choose another vertex nearest to the selected vertex from the previous step.

    int min = INF;
    x = 0;
    y = 0;

    for (int i = 0; i < V; i++) {
      if (selected[i]) {
        for (int j = 0; j < V; j++) {
          if (!selected[j] && G[i][j]) {  // not in selected and there is an edge
            if (min > G[i][j]) {
              min = G[i][j];
              x = i;
              y = j;
            }
          }
        }
      }
    }
    cout << x << " - " << y << " :  " << G[x][y];
    cout << endl;
    selected[y] = true;
    no_edge++;
  }

  return 0;
}
