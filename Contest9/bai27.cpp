#include<bits/stdc++.h>
using namespace std;
int n, m;
bool used[1005];
bool recStack[1005];
vector<int> vt[1005];
bool isCycle(int u){
	if (!used[u]){
		used[u] = true;
		recStack[u] = true;
		for (int i=0; i<vt[u].size(); i++){
			if (!used[vt[u][i]] && isCycle(vt[u][i]))
				return true;
			else if(recStack[vt[u][i]])
				return true;
		}
	}
	recStack[u] = false;
	return false;
}
bool check(){
	for(int i=1; i<=n; i++) 
        if (isCycle(i)) 
            return true; 
    return false; 
}
int main(){
	int T; cin >> T;
	while (T--){
		cin >> n >> m;
		for (int i=0; i<1005; i++)
			vt[i].clear();
		for (int i=1; i<=m; i++){
			int x, y; cin >> x >> y;
			vt[x].push_back(y);
		}
		memset(used, false, sizeof(used));
		memset(recStack, false, sizeof(recStack));
		if (check()) cout << "YES";
		else cout << "NO";
		cout << endl;
	}
}
