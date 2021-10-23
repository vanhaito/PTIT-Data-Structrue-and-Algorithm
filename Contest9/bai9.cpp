#include<bits/stdc++.h>
using namespace std;
int A[1005][1005], n, m ,u;
bool used[1005];
void init(){
	cin >> n >> m >> u;
	memset(A, 0, sizeof(A));
	memset(used, false, sizeof(used));
	for (int i = 1; i <= m; i++){
			int x, y; cin >> x >> y;
			A[x][y] = 1;
	}
}
void BFS(){
	queue<int> Q;
	Q.push(u); used[u] = true;
	while(!Q.empty()){
		int s = Q.front();
		cout << s << " ";
		Q.pop();
		for (int t = 1; t <= n; t++){
			if (!used[t] && A[s][t]){
				Q.push(t);
				used[t] = true;
			}
		}
	}
}
int main(){
	int t; cin >> t;
	while (t--){
		init();
		BFS();
		cout << endl;
	}
}
