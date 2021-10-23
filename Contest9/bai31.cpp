#include<bits/stdc++.h>
using namespace std;
int n;
bool used[1005];
vector<int> adj[1005];
void Tree_DFS(int u){
	vector<vector<int> > vt;
	stack<int> S;
	S.push(u);
	used[u] = true;
	while (!S.empty()){
		int s = S.top();
		S.pop();
		for (int t=0; t<adj[s].size(); t++){
			if (!used[adj[s][t]]){
				vector<int> v;
				v.push_back(s); v.push_back(adj[s][t]);
				vt.push_back(v);
				used[adj[s][t]] = true;
				S.push(s); S.push(adj[s][t]);
				break;
			}
		}
	}
	if (vt.size() < n-1)
		cout << "NO" << endl;
	else cout << "YES" << endl;
}
int main(){
	int T; cin >> T;
	while (T--){
		cin >> n;
		for (int i=0; i<1005; i++)
			adj[i].clear();
		for (int i=1; i<n; i++){
			int x, y; cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		memset(used, false, sizeof(used));
		Tree_DFS(1);
	}
}
