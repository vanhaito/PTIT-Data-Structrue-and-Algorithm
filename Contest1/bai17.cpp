#include<bits/stdc++.h>
using namespace std;

long long binary(long long n){
    if(n==1)    return 1;
    else if(n%2==0) return 10*binary(n/2);
    else    return 10*binary(n/2)+1;
}
\
int main(){
    long long t, n;
    cin>>t;
    while(t--){
        cin>>n;
        long long a=1, b=9;
        while(b%n!=0){
            a++;
            b=9*binary(a);
        }
        cout<<b<<endl;
    }
}
