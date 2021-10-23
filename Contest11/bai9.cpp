#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node *left, *right;
};
Node *CreateNode(int x){
	Node *p = new Node();
	if (!p) exit(1);
	p->data = x;
	p->right = p->left = NULL;
	return p;
}
Node *ConstructTree(int n){
	map<int, Node*> m;
	Node *root = NULL;
	while (n--){
		int a, b; char c;
		cin >> a >> b >> c;
		Node *parent;
		if (m.find(a) == m.end()){
			parent = CreateNode(a);
			m[a] = parent;
			if (root == NULL)
				root = parent;
		}
		else
			parent = m[a];
		Node *child = CreateNode(b);
		if (c == 'L')
			parent->left = child;
		else
			parent->right = child;
		m[b] = child;
	}
	return root;
}
bool isSameLevel(Node *root, int currLevel, int reset){
	static int level = -1;
	if (reset)
		level = -1;
	if (root->left==NULL && root->right==NULL){
		if (level == -1){
			level = currLevel;
			return true;
		}
		else if (level == currLevel)
			return true;
		else
			return false;
	}
	int lRes = true;
	int rRes = true;
	if (root->left)
		lRes = isSameLevel(root->left, currLevel+1, false);
	if (root->right)
		rRes = isSameLevel(root->right, currLevel+1, false);
	if (!lRes || !rRes)
		return false;
	return true;
}
int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		Node *root = ConstructTree(n);
		if (isSameLevel(root, 0, true))
			cout << 1;
		else 
			cout << 0;	
		cout << endl;
	}	
}	                          
