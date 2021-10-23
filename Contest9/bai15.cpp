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
void DFS(int u){
	used[u] = true;
	for (int v = 1; v <= n; v++){
		if (matrix[u][v] && !used[v])
			DFS(v);
	}
}
void TPLT_DFS(){
	for (int u = 1; u <= n; u++){
		if (!used[u]){
			sol++;
			DFS(u);
		}
	}
	cout << sol << endl;
}
int main(){
	int t; cin >> t;
	while (t--){
		init();
		TPLT_DFS();
	}
}
