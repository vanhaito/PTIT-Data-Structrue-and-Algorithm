#include<bits/stdc++.h>
using namespace std;
int arr[30];
int n, k;
bool used[30];

bool canDivide(int start,int k, int subsetSum, int target){
	if(k == 1) return true;
	if(subsetSum == target){
		return canDivide(0, k-1, 0, target);
	}
	for(int i = start; i < n; i++){
		if(!used[i]){
			used[i] = true;
			subsetSum += arr[i];
			if(canDivide(i+1, k, subsetSum, target))
				return true;
			used[i] = false;
		}
	}
}

bool canDivideArray(int k){
	int sumOfAllItems=0;
	for(int i = 0; i < n; i++)
		sumOfAllItems += arr[i];
	if(k == 0 || sumOfAllItems%k != 0) 
		return false;
	int target = sumOfAllItems/k;
	return canDivide(0, k, 0, target);
}


int main(){
	int t; cin>>t;
	while(t--){
		cin>>n>>k;
		for(int i = 0; i < n; i++)
			cin>>arr[i];
		if(canDivideArray(k)) cout<<1<<endl;
		else cout<<0<<endl;
	}
}
