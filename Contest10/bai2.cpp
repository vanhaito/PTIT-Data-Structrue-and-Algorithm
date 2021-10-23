#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int> adj[1005];
bool DFS(int u, int c, bool used[]){
	if (c == n)
		return true;
	used[u] = true;
	for (int v=0; v<adj[u].size(); v++){
		if (!used[adj[u][v]]){
			if (DFS(adj[u][v], c+1, used)){
				return true;
			}
		}
	}
	used[u] = false;
	return false;
}
bool isHamilton(){
	bool used[1005];
	memset(used, false, sizeof(used));
	for (int i=1; i<=n; i++){
		int c = 1;
		if (DFS(i, c, used))
			return true;
	}
	return false;
}
int main(){
	int t; cin >> t;
	while (t--){
		cin >> n >> m;
		for (int i=0; i<1005; i++)
			adj[i].clear();
		for (int i=1; i<=m; i++){
			int x, y; cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		if (isHamilton()) cout << 1;
		else cout << 0;
		cout << endl;
	}
}
