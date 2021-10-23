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
void leftSum(Node *root, Node *parent, int &sum){
	if (root){
		leftSum(root->left, root, sum);
		if (!root->left && !root->right && parent->right==root)
			sum += root->data;
		leftSum(root->right, root, sum);
	}
}
int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		Node *root = ConstructTree(n);
		int sum = 0;
		leftSum(root, root, sum);
		cout << sum << endl;
	}
}
