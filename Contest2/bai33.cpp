#include<bits/stdc++.h>
#define MAX 100
using namespace std;
int X[MAX], A[MAX][MAX], cot[MAX], xuoi[2*MAX], nguoc[2*MAX];

void init(){
	for(int i=1; i<=8; i++)
		for(int j=1; j<=8; j++)
			cin>>A[i][j];
	for(int i=1; i<=8; i++)
		cot[i]=true;
	for(int i=1; i<=2*8-1; i++){
		xuoi[i]=true;
		nguoc[i]=true;
	}
}

int sum(int A[]){
	int s=0;
	for(int i=1; i<=8; i++)
			s+=A[i];
	return s;
}

void Solution(int i, int &max){
	for(int j=1; j<=8; j++){
		if(cot[j] && xuoi[i-j+8] && nguoc[i+j-1]){
			X[i]=A[i][j];
			cot[j]=false; xuoi[i-j+8]=false; nguoc[i+j-1]=false;
			if(i==8){
				int s=sum(X);
				if(s>max) max=s;
			}
			else Solution(i+1, max);
			cot[j]=true; xuoi[i-j+8]=true; nguoc[i+j-1]=true;
		}
	}
}
int main(){
	int t; cin>>t;
	while(t--){
		init();
		int max=0;
		Solution(1, max);
		cout<<max;
	}
}
