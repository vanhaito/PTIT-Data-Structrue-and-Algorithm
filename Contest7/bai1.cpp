#include <bits/stdc++.h>
using namespace std;
int a[205], top = -1;
void push(int n) {
	top++;
	a[top] = n;
}
void pop() {
	top--;
}
void show() {
	if(top >= 0) {
		for(int i=0; i<=top; i++){
			cout << a[i] <<" ";
		}
		cout << endl;
	}
	else {
		cout << "empty" << endl;
	}
}
int main() {
	string s;
	int n;
	while(cin >> s){
		if(s == "push"){
			cin >> n;
			push(n);	
		} 
		else if(s == "pop") {
			pop();		
		}
		else if(s == "show") {
			show();
		}
	}
}
