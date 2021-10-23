#include<bits/stdc++.h>
#define MAX 10000007
typedef long long ll;
ll n, A[MAX], B[MAX];
using namespace std;
void findMissingValue(){
	cin >> n;
	if(n == 1){
		cout << "-1" << endl;	
		return;
	}
	for (int i = 1; i <= n; i++) cin >> A[i];
	ll index = n;
	int  k = 0;
	for (int i = 1; i < n; i++){
		cin >> B[i];
		if (A[i] != B[i] && k == 0){
			index = i;
			k++;
		}
	}
	cout << index << endl;
}
int main(){
	int T; cin >> T;
	while (T--){
		findMissingValue();
	}
}
