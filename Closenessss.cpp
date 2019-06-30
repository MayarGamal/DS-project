
#include <iostream>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;
# define INF 0x3f3f3f3f

typedef pair<int, int> iPair;

class Graph
{
    int V;
    list< pair<int, int> > *adj;

public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    int shortestPathesSum(int s);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<iPair> [V];
}

void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

int Graph::shortestPathesSum(int src)
{
    int sumOfshortPathes =0;
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
    vector<int> dist(V, INF);
    pq.push(make_pair(0, src));
    dist[src] = 0;


    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {

            int v = (*i).first;
            int weight = (*i).second;
            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    for (int i = 0; i < V; ++i)
    {
        sumOfshortPathes +=dist[i];
    }
         return sumOfshortPathes;
}
int main()
{
    int n,m;
    double l,k;
    double*C;
    C=new double[n];
    cin>>n>>m;
    l=n-1;
    int node1,node2,weight;
    Graph MyGraph(n);

    for(int i=0;i<m;i++)
    {
        cin>>node1>>node2>>weight;
    MyGraph.addEdge(node1,node2,weight) ;

    }

    for(int i=0;i<n;i++)
    {

        k=MyGraph.shortestPathesSum(i);
       // cout<<k<<endl;
      C[i]=(l/k);
    }
    for(int i=0;i<n;i++)
    {
        //cout<<"999";
        cout<<C[i]<<'\n';
    }



}
