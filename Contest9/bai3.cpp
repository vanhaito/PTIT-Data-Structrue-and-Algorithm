#include<bits/stdc++.h>
using namespace std;
int matrix[1005][1005];
int main(){
	vector<int> res;
	int n; cin >> n;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++)
			cin >> matrix[i][j];
	}
	for (int i = 1; i <= n; i++){
		res.clear();
		for (int j = 1; j <= n; j++){
			if (matrix[i][j])
				res.push_back(j);
		}
		for (int k = 0; k < res.size(); k++)
			cout << res[k] << " ";
		cout << endl;
	}	
	
}
