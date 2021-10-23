#include<bits/stdc++.h>
using namespace std;
int n, m, s;
struct edge{
	int u;
	int v;
	int w;
};
edge edges[10005];
void bellmanFord(){
	int dist[1005];
	for (int i=1; i<=n; i++)
		dist[i] = INT_MAX;
	dist[s] = 0;
	for(int i=1; i<n; i++){
		for (int j=0; j<m; j++){
			int u = edges[j].u;
			int v = edges[j].v;
			int w = edges[j].w;
			if (dist[u] != INT_MAX && dist[u]+w<dist[v])
				dist[v] = dist[u]+w;
		}
	}
	for (int j=0; j<m; j++){
		int u = edges[j].u;
		int v = edges[j].v;
		int w = edges[j].w;
		if (dist[u] != INT_MAX && dist[u]+w<dist[v]){
			cout << "-1" << endl;
			return;
		}
	}
	for (int i=1; i<=n; i++){
		if (dist[i] == INT_MAX)
			cout << "INFI" << " ";
		else
			cout << dist[i] << " ";
	}
	cout << endl;
}
int main(){
	int t; cin >> t;
	while (t--){
		cin >> n >> m >> s;
		for (int i=0; i<m; i++)
			cin >> edges[i].u >> edges[i].v >> edges[i].w;
		bellmanFord();
	}
}
