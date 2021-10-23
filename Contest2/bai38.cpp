#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans = 1e18;
ll factor[] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
int n;
void DFS(ll tmp, ll nn, ll k){
	if (nn > n) return;
	if ( nn == n){
		if (tmp < ans)
			ans = tmp;
		return;
	}
	for (int i = 1; i <= 64; i++){
		tmp *= factor[k];
		if (tmp >= ans) break;
		if (nn < n) DFS(tmp, nn * (i + 1), k + 1);
	}
}
int main(){
	int t; cin >> t;
	while (t--){
		cin >> n;
		if (n == 1) cout << 1 << endl;
		else{
			DFS(1, 1, 1);
			cout << ans << endl;
		}
		ans = 1e18;
	}
	return 0;
}


