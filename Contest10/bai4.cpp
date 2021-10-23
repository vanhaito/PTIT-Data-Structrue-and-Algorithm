#include<bits/stdc++.h>
using namespace std;
int n, m;
char arr[1005][1005];
bool visited[1005][1005];
int dx[]={-1, +0, +1, +0};
int dy[]={+0, +1, +0, -1};
struct data{
    int i;
    int j;
};
void BFS(){
	memset(visited, false, sizeof(visited));
	int x, y;
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			if (arr[i][j] == 'S'){
				x = i;
				y = j;
				break;
			}
		}
	}
	data tmp;
    tmp.i = y;
    tmp.j = x;
	queue<data> q;
	q.push(tmp);
	visited[y][x] = true;
	while (!q.empty()){
		data u = q.front();
		q.pop();
		for (int i=0; i<4; i++){
			int x_m = u.i+dx[i];
			int y_m = u.j+dy[i];
			if (x_m>=1 && x_m<=n && y_m>=1 && y_m<=m && !visited[y_m][x_m] && arr[y_m][x_m]=='.'){
				tmp.i = y_m;
                tmp.j = x_m;
                q.push(tmp);
                visited[y_m][x_m] = true;
			}
		}
	}
}
void solve(){
	BFS();
	int x, y;
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			if (arr[i][j] == 'T'){
				x = i;
				y = j;
				break;
			}
		}
	}
	if (visited[x][y]) cout << "YES" << endl;
	else cout << "NO" << endl;
}
int main(){
	int t; cin >> t;
	while (t--){
		cin >> n >> m;
		for (int i=1; i<=n; i++)
			for (int j=1; j<=m; j++)
				cin >> arr[i][j];
		solve();
	}
}
