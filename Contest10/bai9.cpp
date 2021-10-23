#include<bits/stdc++.h>
using namespace std;
int n, m, u;
vector<int> adj[1005];
bool used[1005];
void Tree_BFS(){
	vector<vector<int> > vt;
	queue<int> Q;
	Q.push(u);
	used[u] = true;
	while (!Q.empty()){
		int s = Q.front();
		Q.pop();
		for (int t=0; t<adj[s].size(); t++){
			if (!used[adj[s][t]]){
				vector<int> v;
				v.push_back(s);
				v.push_back(adj[s][t]);
				vt.push_back(v);
				Q.push(adj[s][t]);
				used[adj[s][t]] = true;	
			}
		}
	}
	if (vt.size() < n-1)
		cout << "-1" << endl;
	else{
		for (int i = 0; i < vt.size(); i++){
			for (int j = 0; j < vt[i].size(); j++)
				cout << vt[i][j] << " ";
			cout << endl;
		}
	}
}
int main(){
	int t; cin >> t;
	while (t--){
		cin >> n >> m >> u;
		memset(used, false, sizeof(used));
		for (int i=0; i<1005; i++)
			adj[i].clear();
		for (int i=1; i<=m; i++){
			int x, y; cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		Tree_BFS();
	}
}
