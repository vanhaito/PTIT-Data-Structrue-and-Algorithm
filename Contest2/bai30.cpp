#include <iostream> 
#include <vector> 
#include <cmath>
using namespace std;
int n, p, s;
vector<vector<int> > result;
vector<int> set;
vector<int> prime;

void sieve(){
	int pr[200]={0};
	for(int i=2; i*i<=s; i++){
		if(pr[i] == 0){
			for(int j=i*i; j<=s; j+=i)
				pr[j]=1;
		}
	}
	for(int i=p; i<=s; i++){
		if(pr[i]==0)
			prime.push_back(i);
	}
}
void display() 
{ 
    int length=result.size(); 
    cout<<length<<endl;
    for (int i=0; i<length; i++){
    	for(int j=0; j<n; j++)
    		cout<<result[i][j]<<" ";
    	cout<<endl; 
	}
} 
void primeSum(int total, int index) 
{ 
    if (total== s && set.size()==n) 
    { 
       	result.push_back(set); 
        return; 
    } 
    if (total>s || index==prime.size()) 
        return;
    set.push_back(prime[index]); 
    primeSum(total+prime[index], index+1); 
    set.pop_back(); 
    primeSum(total, index+1); 
} 
  
int main(){
	int t; cin>>t;
	while(t--){
		cin>>n>>p>>s;
		sieve();
		primeSum(0, 0);
		display();
		prime.clear();
		result.clear();
	}
}
