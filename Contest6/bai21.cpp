#include<bits/stdc++.h>
using namespace std;
bool cmp(const pair<int,int> &a, const pair<int,int> &b){
	if (a.second == b.second){
		return a.first < b.first;
	}
	return a.second > b.second;
}
void solve(int arr[], int n){
	sort(arr, arr+n);
	vector<pair<int,int> > vt(n);
	int k=0, index=1;
	for (int i=1; i <n; i++){
		if (arr[i] == arr[i-1]) index++;
		else{
			vt[k].first=arr[i-1]; vt[k].second=index;
			k++; index=1;
		}
	} 
	vt[k].first=arr[n-1]; vt[k].second=index; k++;
	sort(vt.begin(), vt.end(), cmp);
	for (int i=0; i<k; i++){
		for (int j=0; j<vt[i].second; j++)
			cout << vt[i].first << " ";
	}
	cout << endl;
}
int main(){
	int T; cin >> T;
	while (T--){
		int n; cin >> n;
		int *arr = new int[n];
		for (int i=0; i<n; i++) cin >> arr[i];
		solve(arr, n);
	}
}
