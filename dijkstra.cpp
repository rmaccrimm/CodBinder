#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#typedef pair<int, int> pii;

/* 
   ~O(Vlog(V))
   Find shortest path between two nodes in a graph  
*/


int main()
{
	int v, e, src, targ;
	cin >> n >> k >> src >> targ;
	
	vector<pii> adj(n);
	for (int i = 0; i < k; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}

	vector<int> dist(n, -1);
	vector<int> prev(n, -1);
	priority_queue<pi, vector<pi>, greater<pi>> Q;
	Q.emplace(src, 0);

	while (!Q.empty()) {
		int u = Q.top().first;
		int d = Q.top().second;
		Q.pop();
		if (dist[u] != -1)
			continue;
		dist[u] = d;
		for (auto v: adj[u]) {
			pq.emplace(d+u.second, u.first);
			prev[v.first] = u;
		}
	}

	vector<int> path;
	
	
}
