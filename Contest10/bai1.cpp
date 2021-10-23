#include<bits/stdc++.h>
using namespace std;
int n, m, p;
int color[1005];
int matrix[1005][1005];
bool isSafe(int v, int c){
	for (int i=1; i<=n; i++)
		if (matrix[v][i] && c==color[i])
			return false;
	return true;
}
bool Try(int v){
	if (v == n+1)
		return true;
	for (int c=1; c<=p; c++){
		if (isSafe(v, c)){
			color[v] = c;
			if (Try(v+1) == true) 
				return true;
			color[v] = 0;
		}
	}
	return false;
}
int main(){
	int t; cin >> t;
	while (t--){
		memset(matrix, 0 , sizeof(matrix));
		memset(color, 0, sizeof(color));
		cin >> n >> m >> p;
		for (int i = 1; i <= m; i++){
			int x, y; cin >> x >> y;
			matrix[x][y] = 1;
			matrix[y][x] = 1;
		}
		if (Try(1) == false)
			cout << "NO" << endl;
		else 
			cout << "YES" << endl;
	}
}
