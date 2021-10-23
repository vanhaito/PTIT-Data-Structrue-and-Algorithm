#include<bits/stdc++.h>
using namespace std;
int main(){
	int dist[105][105];
	for (int i=1; i<=104; i++){
		for (int j=1; j<=104; j++)
			dist[i][j] = 1e9;
	}
	for (int i=1; i<=104; i++)
		dist[i][i] = 0;
	int n, m; cin >> n >> m;
	for (int i=0; i<m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		dist[u][v] = dist[v][u] = w;
	}
	for (int k=1; k<=n; k++){
		for (int i=1; i<=n; i++){
			for (int j=1; j<=n; j++){
				if (dist[i][j] > dist[i][k]+dist[k][j]){
					dist[i][j] = dist[i][k]+dist[k][j];
				}
			}
		}
	}
	int q; cin >> q;
	while(q--){
		int x, y; cin >> x >> y;
		cout << dist[x][y] << endl;
	}
}
