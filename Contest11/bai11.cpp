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
int findDepth(Node *node){
	int depth = 0;
	while (node != NULL){
		depth++;
		node = node->left;
	}
	return depth;
}
bool isPerfectTree(Node *root, int depth, int level=0){
	if (root == NULL)
		return true;
	if (root->left==NULL && root->right==NULL)
		return (depth == level+1);
	if (root->left==NULL || root->right==NULL)
		return false;
	return (isPerfectTree(root->left, depth, level+1) && isPerfectTree(root->right, depth, level+1));
}
int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		Node *root = ConstructTree(n);
		int depth = findDepth(root);
		if (isPerfectTree(root, depth))
			cout << "Yes";
		else
			cout << "No";
		cout << endl;
	}
}
