#include<bits/stdc++.h>
using namespace std;
int n, m;
bool used[1005];
vector<int> vt[1005];
void BFS(int u){
	queue<int> Q;
	Q.push(u);
	used[u] = true;
	while(!Q.empty()){
		int s = Q.front();
		Q.pop();
		for (int t=0; t<vt[s].size(); t++){
			if (!used[vt[s][t]]){
				Q.push(vt[s][t]);
				used[vt[s][t]] = true;	
			}
		}
	}
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
		}
		memset(used, false, sizeof(used));
		int res = 0;
		for (int  i=1; i<=n; i++){
			if (!used[i]){
				res++;
				BFS(i);
			}
		}
		if (res >= 2) cout << "NO";
		else cout << "YES";
		cout << endl;
	}
}
