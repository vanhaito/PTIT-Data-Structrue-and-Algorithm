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
int DFS(int u){
	int c = 1;
	stack<int> St;
	St.push(u); used[u] = true;
	while(!St.empty()){
		int s = St.top();
		St.pop();
		for (int t = 1; t <= n; t++){
			if (!used[t] && matrix[s][t]){
				c++;
				used[t] = true;
				St.push(s);
				St.push(t);
				break;
			}
		}
	}
	return c;
}
void Reinit(){
	for (int i = 1; i <= n; i++)
		used[i] = false;
}
void Dinh_tru_DFS(){
	vector<int> res;
	for (int u = 1; u <= n ; u++){
		used[u] = true;
		if (u == 1){
			if (DFS(2) != n-1)
				res.push_back(u);
		}
		else{
			if (DFS(1) != n-1)
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
		Dinh_tru_DFS();
	}
}

