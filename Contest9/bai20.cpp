#include<bits/stdc++.h>
using namespace std;
int n, m;
int matrix[1005][1005];
bool used[1005];
void init(){
	cin >> n >> m;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			matrix[i][j] = 0;
	for (int i=1; i<=n; i++)
		used[i] = false;
	for (int i = 1; i <= m; i++){
			int x, y; cin >> x >> y;
			matrix[x][y] = 1;
			matrix[y][x] = 1;
	}
}
int BFS(int u){
	int c = 0;
	queue<int> Q;
	Q.push(u);
	used[u] = true;
	while(!Q.empty()){
		int s = Q.front();
		c++;
		Q.pop();
		for (int t = 1; t <= n; t++){
			if (!used[t] && matrix[s][t]){
				Q.push(t);
				used[t] = true;	
			}
		}
	}
	return c;
}
void Reinit(){
	for (int i = 1; i <= n; i++)
		used[i] = false;
}
void Dinh_tru_BFS(){
	vector<int> res;
	for (int u = 1; u <= n ; u++){
		used[u] = true;
		if (u == 1){
			if (BFS(2) != n-1)
				res.push_back(u);
		}
		else{
			if (BFS(1) != n-1)
				res.push_back(u);
		}
		Reinit();
	}
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	cout << endl;
}
int main(){
	int T; cin >> T;
	while (T--){
		init();	
		Dinh_tru_BFS();
	}
}

