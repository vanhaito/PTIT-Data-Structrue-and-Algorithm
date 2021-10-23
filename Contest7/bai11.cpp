#include<bits/stdc++.h> 
using namespace std; 
int prec(char c){ 
    if(c == '^') 
    	return 3; 
    else if(c == '*' || c == '/') 
    	return 2; 
    else if(c == '+' || c == '-') 
    	return 1; 
    else
    	return -1; 
} 
void solve(string s){ 
    stack<char> st; 
    int l = s.length(); 
    string ns; 
    for(int i = 0; i < l; i++) 
    { 
        if((s[i] >= 'a' && s[i] <= 'z')||(s[i] >= 'A' && s[i] <= 'Z')) 
        	ns+=s[i]; 
        else if(s[i] == '(') 
          st.push('('); 
        else if(s[i] == ')') 
        { 
            while(!st.empty() && st.top() != '(') 
            { 
                char c = st.top(); 
                st.pop(); 
                ns += c; 
            } 
            if(st.top() == '(') 
                st.pop(); 
        } 
        else{ 
            while(!st.empty() && prec(s[i]) <= prec(st.top())) 
            { 
                char c = st.top(); 
                st.pop(); 
                ns += c; 
            } 
            st.push(s[i]); 
        } 
    } 
    while(!st.empty()) 
    { 
        char c = st.top(); 
        st.pop();
		if (c != '(') 
        	ns += c; 
    } 
    cout << ns << endl; 
} 
int main() { 
    int t; cin >> t;
    cin.ignore();
    while (t--){
    	string s; cin >> s;
    	solve(s);
	}
	return 0;
} 

