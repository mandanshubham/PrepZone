/*
	1.Implementation of Dijkstra Algorithm is similart to BFS, except we use
	priority queue (min heap) instead of queue.
	2. A distance vector is used to store shortest distance of all other nodes from source node.
	3. No need of a visited vector.
*/

/*
	@source : source node
	@adj : adjacency list {v, weight}
	@n : total number of nodes in the graph
*/

class Solution{
public:
	const int INF = 1e9;
	vector<int> dijkstra(int source, vector<pair<int, int>> adj[], int n) 
	{
		//min heap : {weight, node}
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
		pq.push({0, source}) 

		vector<int> distance(n, INF);
		distance[source] = 0;

		while(!pq.empty())
		{
			int u = pq.top().second;
			int weight = pq.top().first;
			pq.pop();

			for(auto a : adj[u]) 
			{
				int v = p.first;
				int w = p.second;

				if(distance[v] > distance[u] + w) 
				{
					distance[v] = distance[u] + w;
					pq.push({distance[v], v});
				}
			}
		}

		return distance;
	}
};

/*
	Time Complexity : O((E+V)*LogV) = O(ELogV) 
	NOTE : The time complexity of the above algorithm looks O(V^2) as there are two nested while loops. 
	If we take a closer look, we can observe that the statements in the inner loop are executed O(V+E) times (similar to BFS).
	The inner loop has decreaseKey() operation which takes O(LogV) time. So overall time complexity is O(E+V)*O(LogV) which is O((E+V)*LogV) = O(ELogV) 
*/
