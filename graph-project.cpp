#include <iostream>
#include <vector>
#include <list>
#include <math.h>

#define INF 0x3f3f3f3f

using namespace std;


class Graph
{
public:
	int Nodes_num;
	int edges_num;
	int node1, node2;
	int weight;
	vector< list< pair<int, int> > >  adjList;

	Graph(int Nodes, int edges);
	void add_edge(int n1, int n2, int w);
	int minDist(Graph g1, vector<int> dist , vector<bool> visited);
	bool IsConnected(Graph g1, int n1, int n2);
	int closeness_sum(Graph g1, int src, vector<int> dist );
};

Graph::Graph(int Nodes, int edges)
{
	Nodes_num = Nodes;
	edges_num = edges;
	adjList = vector< list< pair<int, int> > >(Nodes_num);
}

void Graph::add_edge(int n1, int n2, int w)
{
	node1 = n1;
	node2 = n2;
	weight = w;
	adjList[node1].push_back(make_pair(node2, weight));
	adjList[node2].push_back(make_pair(node1, weight));

}

int Graph::minDist(Graph g1, vector<int> dist  , vector<bool> visited)
{
	int min = INF;
	int min_index;
	for (int i = 0; i < g1.Nodes_num ; i++)
	{
		if (dist[i] <= min && visited[i] == false )
		{
			min = dist[i];
			min_index = i;
		}
	}
	return min_index;
}

bool Graph::IsConnected(Graph g1, int n1, int n2) 
{
	for (list< pair<int, int> > ::iterator it = g1.adjList[n1].begin();
		it != g1.adjList[n1].end(); it++)
	{
		if (it->first == n2)
			return true;
	}
	return false;
}

int Graph::closeness_sum(Graph g1, int src , vector<int> dist )
{	
	vector<bool> visited(g1.Nodes_num, false);
	
	dist[src] = 0;
	int w;
	
	for (int i = 0; i < g1.Nodes_num - 1; i++)
	{
		int min_node = minDist(g1, dist, visited);
		//cout << "min node" << min_node;

		visited[min_node] = true;

		for (int j = 0; j < g1.Nodes_num; j++)
		{
			if ( !visited[j] && g1.IsConnected(g1, min_node, j))
			{
				//cout << "j  " << j;

				for (list< pair<int, int> > ::iterator it = g1.adjList[min_node].begin();
					it != g1.adjList[min_node].end(); it++)
				{
					if (it->first == j)
					{
						w = it->second;
						break;
					}
				}
				//cout << "w  " << w; 

				if (dist[min_node] != INF && dist[min_node] + w < dist[j])
				{
					dist[j] = dist[min_node] + w;
					//cout << "dist"<< dist[j];
				}
			}
		}
	}
	int sum = 0;
	for (int k = 0; k < g1.Nodes_num; k++)
	{
		sum = sum + dist[k];
	}
	return sum;
}
	

////////////////////////////////

int main()
{
	int Nodes, edges; 
	cin >> Nodes >> edges; 
	vector<int> nodes_edges(Nodes, 0);
	int node1, node2, weight;

	Graph my_graph(Nodes, edges);

	for (int i = 0; i < edges; i++)
	{
		cin >> node1 >> node2 >> weight;
		nodes_edges[node1]++;
		nodes_edges[node2]++;
		my_graph.add_edge(node1, node2, weight);
	}
	
	
	for (int k= 0; k < Nodes; k++)
	{
		cout << nodes_edges[k] << endl;
	}
	cout << "....." << endl; 

	vector<int> dist( my_graph.Nodes_num, INF);
	float sum, ans;
	for (int i = 0; i < Nodes; i++)
	{
		sum = my_graph.closeness_sum(my_graph, i , dist);
		ans = (Nodes - 1) / sum;
		cout << ans << endl ;
	}

}

