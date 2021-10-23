#include<bits/stdc++.h>
using namespace std;
int matrix[1005][1005];
int m, n;
long minSteps(){
	bool visited[n+1][m+1]= {0};
	queue<pair<int, int> > q;
	q.push({1, 1});
	long res = 0;
	while (!q.empty()){
		int x = q.size();
		while (x--){
			pair<int, int> y = q.front(); q.pop();
			int i = y.first; int j = y.second;
			if (visited[i][j]) 
				continue;
			if (i==n && j==m) 
				return res;
			visited[i][j] = 1;
			if (i+matrix[i][j] <= n)
				q.push({i+matrix[i][j], j});
			if (j+matrix[i][j] <= m)	
				q.push({i, j+matrix[i][j]});
		}
		res++;
	}
	return -1;
}
int main(){
	int t; cin >> t;
	while (t--){
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				cin >> matrix[i][j];
		cout << minSteps() << endl;
	}
	return 0;
}
