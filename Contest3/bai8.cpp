#include<bits/stdc++.h>
using namespace std;
struct Job{
	int start;
	int finish;
};
bool compare(Job s1, Job s2){
	return (s1.finish < s2.finish);
}
void solution(Job arr[], int n){
	sort(arr, arr+n, compare);
	int k = 1;
	int i = 0;
	for (int j = 1; j < n ; j++){
		if (arr[j].start >= arr[i].finish){
			k++;
			i = j;
		}
	}
	cout << k << endl;
}
int main(){
	struct Job arr[1005];
	int t, n ; cin >> t;
	while(t--){
		cin >> n;
		for (int i = 0; i < n; i++) cin >> arr[i].start;
		for (int i = 0; i < n; i++) cin >> arr[i].finish;
		solution(arr, n);
	}
}
