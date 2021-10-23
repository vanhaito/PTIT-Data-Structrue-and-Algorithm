#include<bits/stdc++.h>
using namespace std;
struct Job{
	int id;
	int deadline;
	int profit;
};
bool compare(Job a, Job b){
	return (a.profit > b.profit);
}
void solution(Job arr[], int n){
	sort(arr, arr+n, compare);
	int res[n];
	bool slot[n];
	for (int i = 0; i < n; i++)
		slot[i] = false;
	for (int i = 0; i < n; i++){
		for (int j = min(n, arr[i].deadline)-1; j >= 0; j--){
			if (slot[j] == false){
				res[j] = i;
				slot[j] = true;
				break;
			}
		}
	}
	int count = 0, Fmax = 0;
	for (int i =0; i < n; i++)
		if (slot[i]){
			count++;
			Fmax += arr[res[i]].profit;
		}
	cout << count << " " << Fmax << endl;
}
int main(){
	Job arr[1005];
	int t, n; cin >> t;
	while(t--){
		cin >> n;
		for (int i = 0; i < n; i ++)
			cin >> arr[i].id >> arr[i].deadline >> arr[i].profit;
		solution(arr, n);
	}
	return 0;
}
