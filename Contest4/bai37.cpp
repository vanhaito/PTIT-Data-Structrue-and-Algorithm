#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int floorSearch(ll A[], int n, ll x){
	if (x >= A[n])
		return n;
	if (x < A[1])
		return -1;
	for (int i = 1; i <= n; i++){
		if (A[i] > x)
			return i - 1;
	}
	return -1;
}
int main(){
	ll *A, n, x, T; cin >> T;
	while (T--){
		cin >> n >> x; A = new ll[n+2];
		for (int i = 1; i <= n; i++) cin >> A[i];
		cout << floorSearch(A, n, x) << endl;
		delete A;
	}
}
