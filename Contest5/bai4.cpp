#include<bits/stdc++.h>
using namespace std;
int arr[1005], F[1005][55];
int n, k;
int f(int x)
{
    if (x >= 0) return x;
    return x + k;
}
int main(){
 	int T; cin >> T;
	while (T--){
		cin >> n >> k;
		int sum = 0;
		for (int i = 1; i <= n; i++){
			cin >> arr[i];
			arr[i] = arr[i] % k;
			sum = (sum + arr[i]) % k;
		}
		// khoi tao F[0][0] = 0 va cac phan tu con lai bang vo cuc
		F[0][0] = 0;
		for (int i = 1; i < k; i++) F[0][i] = 32000;
		for (int i = 1; i <= n; i++){
			for (int j = 0; j < k; j++)
				F[i][j] = min(F[i-1][j], F[i-1][f(j-arr[i])]+1);
		}
		cout << n-F[n][sum%k] << endl;
	}
}
