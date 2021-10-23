#include<bits/stdc++.h>
using namespace std;
int n, m, sol;
int matrix[1005][1005];
bool used[1005];
void init(){
	cin >> n >> m;
	sol = 0;
	memset(matrix, 0, sizeof(matrix));
	memset(used, false, sizeof(used));
	for (int i = 1; i <= m; i++){
			int x, y; cin >> x >> y;
			matrix[x][y] = 1;
			matrix[y][x] = 1;
	}
}
void BFS(int u){
	queue<int> Q;
	Q.push(u); used[u] = true;
	while(!Q.empty()){
		int s = Q.front();
		Q.pop();
		for (int t = 1; t <= n; t++){
			if (!used[t] && matrix[s][t]){
				Q.push(t);
				used[t] = true;
			}
		}	
	}
}
void TPLT_BFS(){
	for (int u = 1; u <= n; u++){
		if (!used[u]){
			sol++;
			BFS(u);
		}
	}
	cout << sol << endl;
}
int main(){
	int t; cin >> t;
	while (t--){
		init();
		TPLT_BFS();
	}
}
