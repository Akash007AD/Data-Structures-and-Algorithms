#include <stdio.h>
#include <stdlib.h>

// Array to keep track of visited nodes
int visited[7] = {0, 0, 0, 0, 0, 0, 0};

// Adjacency matrix representing the graph
// a[i][j] = 1 means there is an edge between node `i` and node `j`
int a[7][7] = {
    {0, 1, 1, 1, 0, 0, 0},  // Node 0 is connected to 1, 2, 3
    {1, 0, 1, 0, 0, 0, 0},  // Node 1 is connected to 0, 2
    {1, 1, 0, 1, 1, 0, 0},  // Node 2 is connected to 0, 1, 3, 4
    {1, 0, 1, 0, 1, 0, 0},  // Node 3 is connected to 0, 2, 4
    {0, 0, 1, 1, 0, 1, 1},  // Node 4 is connected to 2, 3, 5, 6
    {0, 0, 0, 0, 1, 0, 0},  // Node 5 is connected to 4
    {0, 0, 0, 0, 1, 0, 0}   // Node 6 is connected to 4
};

// Depth First Search function
void DFS(int i) {
    // Print the current node
    printf("%d ", i);

    // Mark the current node as visited
    visited[i] = 1;

    // Check all nodes to find connected and unvisited nodes
    for (int j = 0; j < 7; j++) {
        // If there's an edge between the current node `i` and node `j`
        // and node `j` hasn't been visited
        if (a[i][j] == 1 && !visited[j]) {
            // Recursively perform DFS on node `j`
            DFS(j);
        }
    }
}

int main() {
    // Start DFS traversal from node 0
    DFS(0);

    return 0;
}


// Graph representation based on the adjacency matrix:
//
//          (0)
//         / | \
//       (1) | (2)
//        \  |  |
//         (3)--(4)
//             /   \
//           (5)   (6)
//
// Explanation:
// - Node 0 is connected to nodes 1, 2, and 3.
// - Node 1 is connected to nodes 0 and 2.
// - Node 2 is connected to nodes 0, 1, 3, and 4.
// - Node 3 is connected to nodes 0, 2, and 4.
// - Node 4 is connected to nodes 2, 3, 5, and 6.
// - Node 5 is connected to node 4.
// - Node 6 is connected to node 4.
