#include<bits/stdc++.h>
using namespace std;
long long arr[20][20], tmp[20], n;
long long minCost = INT_MAX, smallest = INT_MAX, total = 0;
bool visit[20];
void init(){
	cin >> n;
	tmp[1] = 1;
	for (int i = 1; i <= n; i++){
		visit[i] = false;
		for (int j = 1; j <= n; j++){
			cin >> arr[i][j];
			if (arr[i][j])
				smallest = min(smallest, arr[i][j]);
		}
	}
	visit[1] = true;
}
void Solution(int k){
	if (total + smallest * (n - k + 1) >= minCost)	
		return;
	for (int i = 1; i <= n; i++){
		if (!visit[i]){
			tmp[k] = i;
			visit[i] = true;
			total += arr[tmp[k-1]][i];
			if (k == n){
				if (total + arr[tmp[n]][tmp[1]] < minCost)
					minCost = total + arr[tmp[n]][tmp[1]];
			}
			else Solution(k+1);
			total -= arr[tmp[k-1]][tmp[k]];
			visit[i] = false;
		}
	}
}
int main(){
	init();
	Solution(2);
	cout << minCost;
}
