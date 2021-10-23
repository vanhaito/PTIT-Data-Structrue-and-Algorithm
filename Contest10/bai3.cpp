#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int> adj[1005];
int mark[1005];
bool bfs(int u){
	queue<int> q;
	q.push(u);
	mark[u] = 1;
	while (!q.empty()){
		int s = q.front();
		q.pop();
		for (int t: adj[s]){
			if (mark[s] == mark[t]) 
				return false;
			else if (!mark[t]){
				q.push(t);
				mark[t] = 3-mark[s];
			}
		}
	}
	return true;
}
void solve(){
	memset(mark, 0, sizeof(mark));
	for (int i=1; i<=n; i++){
		if (mark[i]) continue;
		if (!adj[i].size()){
			mark[i] = 1;
			continue;
		}
		if (!bfs(i)){
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
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
		solve();
	}
}
