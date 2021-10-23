#include<bits/stdc++.h>
using namespace std;
int matrix[505][505];
int n, m;
int biggestSquare(){
	int F[n][m];
	int dmax;
	for (int i = 0; i < n; i++)
		F[i][0] = matrix[i][0];
	for (int j = 0; j < m; j++)
		F[0][j] = matrix[0][j];
	for (int i = 1; i < n; i++){
		for (int j = 1; j < m; j++){
			if (matrix[i][j])
				F[i][j] = min(F[i][j-1], min(F[i-1][j], F[i-1][j-1])) + 1;
			else 
				F[i][j] = 0;
		}
	}
	dmax = F[0][0];
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (dmax < F[i][j])
				dmax = F[i][j];
		}
	}
	return dmax;
}
int main(){
	int T; cin >> T;
	while (T--){
		cin >> n >> m;
		for (int i =0 ; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> matrix[i][j];
		cout << biggestSquare() << endl;
	}
}
