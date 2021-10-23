#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef pair<int, int> iPair;
int n, m, s;
vector<iPair> adj[1005];
void dijkstra(){
	priority_queue<iPair, vector<iPair>, greater<iPair> > pq;
	vector<int> dist(n+1, INT_MAX);
	pq.push(mp(0, s));
	dist[s] = 0;
	while (!pq.empty()){
		int u = pq.top().second;
		pq.pop();
		for(auto x: adj[u]){
			int v = x.first;
			int w = x.second;
			if (dist[v] > dist[u]+w){
				dist[v] = dist[u]+w;
				pq.push(mp(dist[v], v));
			}
		}
	}
	for (int i=1; i<=n; i++)
		cout << dist[i] << " ";
	cout << endl;
}
int main(){
	int t; cin >> t;
	while (t--){
		cin >> n >> m >> s;
		for (int i=0; i<1005; i++)
			adj[i].clear();
		while(m--){
			int u, v, w; cin >> u >> v >> w;
			adj[u].push_back(mp(v, w));
			adj[v].push_back(mp(u, w));
		}
		dijkstra();
	}
}
