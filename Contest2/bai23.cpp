#include<bits/stdc++.h>
using namespace std;

int a[100][100], dau[100][100], n;
vector <string> s;
string ans = ""; 

void init(){
	ans = "";
	s.clear();
	for(int i = 0; i < 100; i++)
		for(int j = 0; j < 100; j++){
			dau[i][j] = 0;
			a[i][j]=0;
		}
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> a[i][j];
}
void Try(int i, int j){
	if(a[0][0] == 0 || a[n-1][n-1] == 0) return;
	if (i == n-1 && j == n-1){
		s.push_back(ans);
	}
	if (i != n-1 && a[i+1][j] == 1 && dau[i+1][j] == 0){
		ans += 'D';
		dau[i][j] = 1;
		Try(i+1, j);
		ans.erase(ans.length()-1);
		dau[i][j] = 0;
	}
	if (j != n-1 && a[i][j+1] == 1 && dau[i][j+1] == 0){
		ans += 'R';
		dau[i][j] = 1;
		Try(i, j+1);
		ans.erase(ans.length()-1);
		dau[i][j] = 0;
	}
	if(j != 0 && j < n && a[i][j-1] == 1 && dau[i][j-1] == 0){
		ans +='L';
		dau[i][j] = 1;
		Try(i, j-1);
		ans.erase(ans.length()-1);
		dau[i][j] = 0;
	}
	if (i != 0 && a[i-1][j] == 1 && dau[i-1][j] == 0){
		ans += 'U';
		dau[i][j] = 1;
		Try(i-1, j);
		ans.erase(ans.length()-1);
		dau[i][j] = 0;
	}
}
void solve(){
	Try(0, 0);
	sort(s.begin(), s.end());
	if(s.empty()) cout << "-1"<<endl;
	else{
        for(int i=0;i<s.size();i++){
            cout << s[i]<<" ";
        }
        cout << endl;
    }
}
int main(){
	int t; cin >> t;
	while(t--){
		init();
		solve();
	}
}
