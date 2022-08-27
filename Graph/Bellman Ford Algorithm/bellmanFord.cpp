class Solution{
public:
	const int INF = 1e8;
	vector <int> bellman_ford(int n, vector<vector<int>> adj, int src) 
	{
		int edges = adj.size();
		vector<int> dist(n, INF);
		dist[src] = 0;

		// Relax all edges n - 1 times. A simple
		// shortest path from src to any other
		// vertex can have at-most n - 1 edges
		for(int i=0; i<n-1; i++) {
		    for(int j=0; j<edges; j++) {
			int u = adj[j][0];
			int v = adj[j][1];
			int w = adj[j][2];

			if(dist[u]!=INF and dist[u] + w < dist[v])
			dist[v] = dist[u] + w;
		    }
		}

		// one more step to ensure whether the graph contains a negative cycle or not
		for(int j=0; j<edges; j++) {
		    int u = adj[j][0];
		    int v = adj[j][1];
		    int w = adj[j][2];

		    if(dist[u]!=INF and dist[u] + w < dist[v])
		    cout<<"Alert! Graph contains a negative cycle";
		}        

		return dist;
    }
};
