#include<bits/stdc++.h>
using namespace std;
struct node{
	char value;
	node *left, *right;
};
bool isOperator(char c){
	if (c=='+'||c=='-'||c=='*'||c=='/') 
		return true;
	return false;
}
node* newNode(int v){
	node *tmp = new node;
	tmp->left = tmp->right = NULL;
	tmp->value = v;
	return tmp;
}
node* Tree(string postFix){
	stack<node *> st;
	node *t, *t1, *t2;
	for (int i=0; i<postFix.length(); i++){
		if (!isOperator(postFix[i])){
			t = newNode(postFix[i]);
			st.push(t);
		}
		else{
			t = newNode(postFix[i]);
			t1 = st.top(); st.pop();
			t2 = st.top(); st.pop();
			t->right = t1;
			t->left = t2;
			st.push(t);
		}
	}
	t = st.top();
	st.pop();
	return t;
}
void Result(node *t){
	if (t){
		Result(t->left);
		cout << t->value << " ";
		Result(t->right);
	}
}
int main(){
	int t; cin >> t;
	while (t--){
		string postFix; cin>>postFix;
		node *res = Tree(postFix);
		Result(res);
		cout << endl;
	}
}
