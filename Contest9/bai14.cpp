#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int> vt[1005];
bool used[1005];
int f[1005];
void BFS(int u, int v){
	queue<int> Q;
	Q.push(u); used[u] = true;
	while(!Q.empty()){
		int s = Q.front();
		Q.pop();
		if (s == v){
			cout << "YES";
			return;
		}
		for (int t=0; t<vt[s].size(); t++){
			if (!used[vt[s][t]]){
				f[vt[s][t]] = s;
				used[vt[s][t]] = true;
				Q.push(vt[s][t]);
			}
		}
	}
	cout << "NO";
}
void solve(int s, int e){
    if(f[e] == 0) 
		cout << "NO" << endl;
    else
    	cout << "YES" << endl;
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
		int q; cin >> q;
		while (q--){
			memset(used, false, sizeof(used));
			int s, e;
			cin >> s >> e;
			BFS(s, e);
			cout << endl;
		}
	}
}


