#include<bits/stdc++.h>
using namespace std;
struct Pair{
	int a;
	int b;
};
bool compare(Pair s1, Pair s2){
	return s1.a < s2.a;
}
void solve(Pair arr[], int n){
	int max = 0;
	int F[n+2];
	sort(arr, arr+n, compare);
	for (int i = 0; i < n; i++)
		F[i] = 1;
	for (int i = 1; i < n; i++){
		for (int j = 0; j < i; j++){
			if (arr[i].a > arr[j].b && F[i] < F[j] + 1)
				F[i] = F[j] + 1;
		}
	}
	for (int i = 0; i < n; i++)
		if (max < F[i])
			max = F[i];
	cout << max << endl;
}
int main(){
	int T; cin >> T;
	while (T--){
		Pair arr[105];
		int n; cin >> n;
		for (int i = 0; i < n; i++)
			cin >> arr[i].a >> arr[i].b;
		solve(arr, n);
	}
}
