#include <stdio.h>
#include <Stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};
int isFull(struct queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty(struct queue *q)
{
    if (q->r == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void enqueue(struct queue *q, int val)
{
    if (isFull(q))
    {
        printf("Queue is Full\n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
    }
}
int dequeue(struct queue *q)
{   
    int a=-1;
    if (isEmpty(q))
    {
        printf("Queue is Empty\n");
    }
    else
    {
        q->f++;
        a= q->arr[q->f];
    }
    return a;
}
int main()
{
    // Declare and initialize the queue
    struct queue q;
    q.size = 100;                 // Set the size of the queue
    q.f = q.r = -1;               // Initialize front and rear indices to -1 (empty queue)
    q.arr = (int *)malloc(q.size * sizeof(int)); // Allocate memory for the queue array

    // Declare variables
    int u; // Variable used for BFS node traversal (not used directly in this case)
    int i = 0; // Starting node for BFS

    // Visited array to keep track of visited nodes
    int visited[7] = {0, 0, 0, 0, 0, 0, 0}; // All nodes initially unvisited (0)

    // Adjacency matrix representation of the graph
    // 7x7 matrix where a[i][j] = 1 indicates an edge between node i and node j
    int a[7][7] = {
        {0, 1, 1, 1, 0, 0, 0}, // Node 0 is connected to nodes 1, 2, 3
        {1, 0, 1, 0, 0, 0, 0}, // Node 1 is connected to nodes 0, 2
        {1, 1, 0, 1, 1, 0, 0}, // Node 2 is connected to nodes 0, 1, 3, 4
        {1, 0, 1, 0, 1, 0, 0}, // Node 3 is connected to nodes 0, 2, 4
        {0, 0, 1, 1, 0, 1, 1}, // Node 4 is connected to nodes 2, 3, 5, 6
        {0, 0, 0, 0, 1, 0, 0}, // Node 5 is connected to node 4
        {0, 0, 0, 0, 1, 0, 0}  // Node 6 is connected to node 4
    };

    // Start BFS from the initial node (node 0)
    printf("%d ", i);    // Print the starting node
    visited[i] = 1;      // Mark the starting node as visited
    enqueue(&q, i);      // Add the starting node to the queue for exploration

    // BFS loop: Continue while there are nodes in the queue
    while (!isEmpty(&q))
    {
        int node = dequeue(&q); // Get the next node to explore from the queue

        // Check all neighbors of the current node
        for (int j = 0; j < 7; j++)
        {
            // If there's an edge to node 'j' and 'j' hasn't been visited
            if (a[node][j] == 1 && visited[j] == 0)
            {
                printf("%d ", j);  // Print the neighbor node
                visited[j] = 1;    // Mark the neighbor as visited
                enqueue(&q, j);    // Add the neighbor to the queue for further exploration
            }
        }
    }

    // Free allocated memory for the queue
    free(q.arr);

    return 0; // Exit the program
}
