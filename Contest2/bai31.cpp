#include<bits/stdc++.h>
using namespace std;
int k, m, n;
string dict[100];
char a[100][100];
bool used[100][100];
vector<string> result;
bool isWord(string& s){
	for (int i = 0; i < k; i++){
		if (s.compare(dict[i]) == 0)
			return true;
	}
	return false;
}
void DFS(int i, int j, string& s){
	used[i][j] = true;
	s = s + a[i][j];
	if (isWord(s))
		result.push_back(s);
	for (int x = i - 1; x <= i + 1 && x < m; x++)
		for (int y = j - 1; y <= j + 1 && y < n; y++)
			if (x >= 0 && y >=0 && !used[x][y])
				DFS(x, y, s);
	s.erase(s.length()-1);
	used[i][j] = false;
}
void input(){
	cin >> k >> m >> n;
	for (int i = 0; i < k; i++)
		cin >> dict[i];
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	memset(used, false, sizeof(used));
}
void solve(){
	result.clear();
	string s = "";
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			DFS(i, j, s);
	if(result.empty()) cout << "-1"<< endl;
	else{
		for(int i = 0; i < result.size(); i++)
			cout << result[i] << " ";
		cout << endl;
	}
}
int main(){
	int t; cin >> t;
	while(t--){
		input();
		solve();
	}
	return 0;
}
