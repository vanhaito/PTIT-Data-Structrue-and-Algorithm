#include<bits/stdc++.h> 
using namespace std;   
const int MAX_CHAR = 26;   
void rearrangeString(string str){ 
    int n = str.length();
    int count[MAX_CHAR] = {0}; 
    for (int i = 0 ; i < n ; i++) 
        count[str[i]-'a']++; 
    priority_queue < pair< int, char> > pq;
    for (char c = 'a' ; c <= 'z' ; c++){	
        if (count[c-'a']) {
        	pair <int, char > x; x.first = count[c-'a'];x.second = c;
        	pq.push(x);
		}             
  	}    
    str = "" ; 
    pair <int, char> prev(-1, '#');        
    while (!pq.empty()) { 
        pair <int, char >k;  
        k = pq.top(); 
        pq.pop();
        str = str + k.second;
        if (prev.first > 0)
            pq.push(prev);   
        k.first--; 
        prev = k; 
    } 
    if (n != str.length()) 
        cout << "-1" << endl;   
    else  
        cout <<1<< endl; 
} 

int main() { 
    string str; int T; cin>>T;
    while(T--){
    	cin>>str;
    	rearrangeString(str);	
	}
} 
