#include<bits/stdc++.h>
using namespace std;
struct Node{
	string data;
	Node *left, *right;
};
Node *CreateNode(string x){
	Node *p = new Node();
	if (!p) exit(1);
	p->data = x;
	p->right = p->left = NULL;
	return p;
}
Node *insert(Node *root, vector<string> v, int i, int n){
	if (i < n){
		Node *temp = CreateNode(v[i]);
		root = temp;
		root->left = insert(root->left, v, 2*i+1, n);
		root->right = insert(root->right, v, 2*i+2, n); 
	}
	return root;
}
int toInt(string s){
	int num=0;
	for (int i=0; i<s.length(); i++)
		num = num*10+(s[i]-'0');
	return num;
}
int solve(Node *root){
	if (!root)
		return 0;
	if (!root->left && !root->right)
		return toInt(root->data);
	int lval = solve(root->left);
	int rval = solve(root->right);
	if (root->data == "+")
		return lval+rval;
	if (root->data == "-")
		return lval-rval;
	if (root->data == "*")
		return lval*rval;
	return lval/rval;
}
int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		vector<string> v;
		while (n--){
			string s; cin >> s;
			v.push_back(s);
		}
		Node *root = insert(root, v, 0, v.size());
		Node *p = root->right->right;
		cout << solve(root) << endl;
	}
}

