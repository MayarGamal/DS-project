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

	Graph(int Nodes);
	void add_edge(int n1, int n2, int w);
	int minDist(vector<int> dist, vector<bool> visited);
	bool IsConnected(int n1, int n2);
	int GETweight(int n1, int n2);
	int closeness_sum(int src, vector<int> dist);
	vector< vector <int>> Betwenees(int src);
	vector<float> Betweeness_calc(vector<vector<int >> path  , int path_num ,  vector<float> g , float prev);
	float sizeOfPath(vector<vector<int >> path, int path_num);

};

Graph::Graph(int Nodes)
{
	Nodes_num = Nodes;
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

int Graph::minDist(vector<int> dist, vector<bool> visited)
{
	int min = INF;
	int min_index;
	for (int i = 0; i < Nodes_num; i++)
	{
		if (dist[i] <= min && visited[i] == false)
		{
			min = dist[i];
			min_index = i;
		}
	}
	return min_index;
}

bool Graph::IsConnected(int n1, int n2)
{
	for (list< pair<int, int> > ::iterator it = adjList[n1].begin();
		it != adjList[n1].end(); it++)
	{
		if (it->first == n2)
			return true;
	}
	return false;
}

int Graph::GETweight(int n1, int n2)
{
	for (list< pair<int, int> > ::iterator it = adjList[n1].begin();
		it != adjList[n1].end(); it++)
	{
		int w;
		if (it->first == n2)
		{
			w = it->second;
			return w;
		}
	}
}

int Graph::closeness_sum(int src, vector<int> dist)
{
	vector<bool> visited(Nodes_num, false);

	dist[src] = 0;

	int w;

	for (int i = 0; i < Nodes_num - 1; i++)
	{
		int min_node = minDist(dist, visited);
		//cout << "min node" << min_node;

		visited[min_node] = true;

		for (int j = 0; j < Nodes_num; j++)
		{
			if (!visited[j] && IsConnected(min_node, j))
			{
				//cout << "j  " << j;

				w = GETweight(min_node, j);
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
	for (int k = 0; k < Nodes_num; k++)
	{
		sum = sum + dist[k];
	}
	return sum;
}




int main()
{
	int Nodes, edges;
	cin >> Nodes >> edges;
	vector<int> nodes_edges(Nodes, 0);
	int node1, node2, weight;

	Graph my_graph(Nodes);

	for (int i = 0; i < edges; i++)
	{
		cin >> node1 >> node2 >> weight;
		nodes_edges[node1]++;
		nodes_edges[node2]++;
		my_graph.add_edge(node1, node2, weight);
	}


/*	for (int k = 0; k < Nodes; k++)
	{
		cout << nodes_edges[k] << "\n";
	}
	cout << "....." << "\n";
	*/

	vector<int> dist(my_graph.Nodes_num, INF);

	float sum, ans;
	for (int i = 0; i < Nodes; i++)
	{
		sum = my_graph.closeness_sum( i, dist);
		ans = (Nodes - 1) / sum;
		cout << ans << "\n";
	}



//for all nodes



}
