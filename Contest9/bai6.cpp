#include<bits/stdc++.h>
int A[1005][1005], n, m, u;
bool used[1005];
using namespace std;

void init(){
	cin >> n >> m >> u;
	memset(A, 0, sizeof(A));
	memset(used, false, sizeof(used));
	for (int i = 1; i <= m; i++){
			int x, y; cin >> x >> y;
			A[x][y] = 1;
			A[y][x] = 1;
	}
}
void DFS(){
	stack<int> St;
	St.push(u); used[u] = true;
	cout << u << " ";
	while(!St.empty()){
		int s = St.top();
		St.pop();
		for (int t = 1; t <= n; t++){
			if (!used[t] && A[s][t]){
				cout << t << " ";
				used[t] = true;
				St.push(s);
				St.push(t);
				break;
			}
		}
	}
}
int main(){
	int t; cin >> t;
	while (t--){
		init();
		DFS();
		cout << endl;
	}
}
