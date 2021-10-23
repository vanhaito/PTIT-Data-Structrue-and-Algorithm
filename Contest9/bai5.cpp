#include<bits/stdc++.h>
using namespace std;
int matrix[1005][1005];
int main(){
	int t; cin >> t;
	vector<int> res;
	while (t--){
		memset(matrix, 0, sizeof(matrix));
		int n, m; cin >> n >> m;
		for (int i = 1; i <= m; i++){
			int x, y; cin >> x >> y;
			matrix[x][y] = 1;
		}
		for (int i = 1; i <= n; i++){
			res.clear();
			for (int j = 1; j <= n; j++){
				if (matrix[i][j])
					res.push_back(j);
			}
			cout << i << ": ";
			for (int k = 0; k < res.size(); k++)
				cout << res[k] << " ";
			cout << endl;
		}	
	}
}
