#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int , int> pii;

void dijkstra(int V , vector<pii> adj[] , int src)
{
     vector<int> dist(V , INT_MAX);
     dist[src] = 0;

     priority_queue<pii , vector<pii> , greater<pii>> pq;
     pq.push({0 , src});

     while(!pq.empty())
     {
         int u = pq.top().second;
         pq.pop();

         for(auto& edge : adj[u])
         {
             int v = edge.first;
             int weight = edge.second;

             if(dist[v] > dist[u] + weight)
             {
                 dist[v] = dist[u] + weight;
                 pq.push({dist[v] , v});
             }
         }
     }

     cout << "Vertex\tDistance from Source\n";
     for(int i = 0 ; i < V ; ++i)
     {
         cout << i << "\t" << dist[i] << "\n";
     }
}

int main()
{
    int V = 5;
    vector<pii> adj[V];

    adj[0].push_back({1, 10});
    adj[0].push_back({2, 3});
    adj[1].push_back({3, 2});
    adj[1].push_back({2, 1});
    adj[2].push_back({1, 4});
    adj[2].push_back({3, 8});
    adj[2].push_back({4, 2});
    adj[3].push_back({4, 7});
    adj[4].push_back({3, 9});

    dijkstra(V, adj, 0);
    return 0;
}
