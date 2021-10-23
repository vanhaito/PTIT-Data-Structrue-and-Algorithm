#include<bits/stdc++.h>
using namespace std;
int n, m;
int matrix[1005][1005];
int minCost(){
	for (int i = 1; i < n; i++)
		matrix[i][0] += matrix[i-1][0];
	for (int j = 1; j < m; j++)
		matrix[0][j] += matrix[0][j-1];
	for (int i = 1; i < n; i++){
		for (int j = 1; j < m; j++){
			matrix[i][j] += min(matrix[i-1][j-1], min(matrix[i][j-1], matrix[i-1][j]));
		}
	}
	return matrix[n-1][m-1];
}
int main(){
	int T; cin >> T;
	while (T--){
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> matrix[i][j];
		cout << minCost() << endl;
	}
}
