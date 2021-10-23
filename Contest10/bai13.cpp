#include<bits/stdc++.h>
using namespace std;
int n, m;
struct edge{
	int u;
	int v;
	int w;
};
edge edges[10005];
bool isNegCycle(int k, int dis[]){
	for (int i=1; i<=n; i++)
		dis[i] = INT_MAX;
	dis[k] = 0;
	for (int i=1; i<=n; i++){
		for (int j=0; j<m; j++){
			int u = edges[j].u;
			int v = edges[j].v;
			int w = edges[j].w;
			if (dis[u] != INT_MAX && dis[u]+w<dis[v])
				dis[v] = dis[u]+w;
		}
	}
	for (int i=0; i<m; i++){
		int u = edges[i].u;
		int v = edges[i].v;
		int w = edges[i].w;
		if (dis[u] != INT_MAX && dis[u]+w<dis[v]){
			return true;
		}
	}
	return false;
}
void solve(){
	bool visited[10005]; 
    memset(visited, 0, sizeof(visited));
    int dis[10005];
    for (int i=1; i<=n; i++){
    	if (!visited[i])
    		if(isNegCycle(i, dis)){
    			cout << 1 << endl;
    			return;
			}
	}
	cout << 0 << endl;
}
int main(){
	int t; cin >> t;
	while (t--){
		cin >> n >> m;
		for (int i=0; i<m; i++)
			cin >> edges[i].u >> edges[i].v >> edges[i].w;
		solve();
	}
}
