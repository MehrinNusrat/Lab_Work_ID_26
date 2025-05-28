#include<iostream>
#include<limits.h>
using namespace std;

#define V 8  //Number of vertices

// Function to find the vertex with minimum key value
int minKey(int key[] , bool mstSet[])
{
    int min = INT_MAX , min_index;

    for(int v = 0 ; v < V ; v++)
    {
        if(!mstSet[v] && key[v] < min)
        {
            min = key[v] , min_index = v;
        }
    }
    return min_index;
}

// Function to print MST
void printMST(int parent[] , int graph[V][V])
{
    cout << "Edge \tWeight\n";

    for(int i = 1 ; i < V ; i++)
    {
        cout << parent[i] << "-" << i << "\t" << graph[i][parent[i]] << "\n";
    }
}

// Prim's Algorithm
void primMST(int graph[V][V])
{
    int parent[V];
    int key[V];
    bool mstSet[V];

    for(int i = 0 ; i < V ; i++)
    {
        key[i] = INT_MAX , mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for(int count = 0 ; count < V - 1 ; count++)
    {
        int u = minKey(key , mstSet);
        mstSet[u] = true;

        for(int v = 0 ; v < V ; v++)
        {
            if(graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
            {
                parent[v] = u , key[v] = graph[u][v];
            }
        }
    }

    printMST(parent , graph);
}

int main()
{
    int graph[V][V] = {
        {0, 14, 8, 6, 5, 0, 0, 0},  //A
        {14, 0, 3, 0, 0, 0, 0 , 0}, //B
        {8, 3 , 0, 0, 0, 10, 0, 0}, //C
        {6, 0, 0, 0, 12, 0, 0, 0},  //D
        {5, 0, 0, 12, 0, 7, 9, 0},  //E
        {0, 0, 10, 0, 7, 0, 0, 15}, //F
        {0, 0, 0, 0, 9, 0, 0, 0},   //G
        {0, 0, 0, 0, 0, 15, 0, 0}   //H
    };

    primMST(graph);

    return 0;
}
