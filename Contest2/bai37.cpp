#include<bits/stdc++.h>
using namespace std;
int n, m, matran[25][25];
int kqua;

void nhap(){
	for (int i = 0; i < 25; i++){
			for (int j = 0; j < 25; j++) matran[i][j] = 0;
		}
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		matran[x][y] = 1;
		matran[y][x] = 1;
	}
}
void DFS(int u, int temp){
	kqua = max(kqua, temp);
	for( int v = 0; v < n; v++){
		if (matran[u][v] == 1){
			matran[u][v] = 0;
			matran[v][u] = 0;
			DFS(v, temp + 1);
			matran[u][v] = 1;
			matran[v][u] = 1;	
		}
	}
}
int main(){
	int t; cin >> t;
	while(t--){
		nhap();
		kqua = -1;
		for (int u = 0; u < n; u++)
			DFS(u, 0);
		cout << kqua << endl;
	}
}
