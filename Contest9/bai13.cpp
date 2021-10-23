#include<bits/stdc++.h>
using namespace std;
int n, m, s, e, matrix[1005][1005], f[1005];
bool used[1005];
void init(){
	cin >> n >> m >> s >> e;
	memset(matrix, 0, sizeof(matrix));
	memset(f, 0, sizeof(f));
	memset(used, false, sizeof(used));
	for (int i = 1; i <= m; i++){
			int x, y; cin >> x >> y;
			matrix[x][y] = 1;
	}
}
void BFS(int u){
	queue<int> Q;
	Q.push(u); used[u] = true;
	while(!Q.empty()){
		int s = Q.front();
		Q.pop();
		for (int t = 1; t <= n; t++){
			if (!used[t] && matrix[s][t]){
				f[t] = s;
				used[t] = true;
				Q.push(t);
			}
		}
	}
}
void BFS_Path(int s, int t){
    if(f[t] == 0)
        cout << "-1" << endl;
    else
    {
    	vector<int> res;
        res.push_back(t);
		int u = f[t];
        while(u != s)
        {
            res.push_back(u);
            u = f[u];
        }
        res.push_back(s);
        for (int i = res.size()-1; i >= 0; i--)
        	cout << res[i] << " ";
        cout << endl;
    }
}
int main(){
	int T; cin >> T;
	while (T--){
		init();
		BFS(s);
		BFS_Path(s, e);
	}
}

