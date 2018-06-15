// C++ program for implementation of Ford Fulkerson algorithm
#include <iostream>
#include <limits.h>
#include <string.h>
#include <queue>
using namespace std;


#define V 101


bool bfs(int rGraph[V][V], int s, int t, int parent[])
{

    bool visited[V];
    memset(visited, 0, sizeof(visited));


    queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v=0; v<V; v++)
        {
            if (visited[v]==false && rGraph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return (visited[t] == true);
}

int fordFulkerson(int graph[V][V], int s, int t)
{
    int u, v;

    int rGraph[V][V];

    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
             rGraph[u][v] = graph[u][v];

    int parent[V];
    int max_flow = 0;
k
    while (bfs(rGraph, s, t, parent))
    {

        int path_flow = INT_MAX;
        for (v=t; v!=s; v=parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        for (v=t; v != s; v=parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

int main()
{
  int vertex;
  int connections;
  int start;
  int finish;
  cin >> vertex >> connections >> start >> finish;

  int graph[V][V];

    for (int i = 0; i < V ; i++){
      for (int j = 0; j < V; j++){
        graph[i][j] = 0;
      }
    }

    int i;
    int j;
    int speed;
    for (int k = 0; k < connections; k++){
      cin >> i >> j >> speed;
      graph[i-1][j-1] = speed;
      graph[j-1][i-1] = speed;
    }



    cout  << fordFulkerson(graph, start - 1 , finish - 1) << endl;

    return 0;
}
