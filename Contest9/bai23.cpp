#include<bits/stdc++.h>
using namespace std;
int n, m;
bool used[1005];
int f[1005];
vector<int> vt[1005];
bool isCycle(int u){
	queue<int> Q;
	Q.push(u);
	used[u] = true;
	while(!Q.empty()){
		int s = Q.front();
		Q.pop();
		for (int t=0; t<vt[s].size(); t++){
			if (!used[vt[s][t]]){
				f[vt[s][t]] = s;
				Q.push(vt[s][t]);
				used[vt[s][t]] = true;	
			}
			else if (f[s] != vt[s][t])
				return true;
		}
	}
	return false;
}
bool check(){
	for (int i=1; i<=n; i++){
		if (!used[i] && isCycle(i))
			return true;
	}
	return false;
}
int main(){
	int T; cin >> T;
	while (T--){
		cin >> n >> m;
		for (int i=0; i<1005; i++)
			vt[i].clear();
		for (int i=1; i<=m; i++){
			int x, y; cin >> x >> y;
			vt[x].push_back(y);
			vt[y].push_back(x);
		}
		memset(used, false, sizeof(used));
		if (check()) cout << "YES";
		else cout << "NO";
		cout << endl;
	}
}
