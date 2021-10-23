#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node *left, *right;
};
typedef Node *Tree;
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
void store(Node *root, auto &set){
	if (!root)
		return;
	store(root->left, set);
	set.insert(root->data);
	store(root->right, set);
}
void convert(Node *root, auto &it){
	if (!root)
		return;
	convert(root->left, it);
	root->data = *it;
	it++;
	convert(root->right, it);
}
void inorder(Node *root){
	if (root){
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}
}
int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		Node *root = ConstructTree(n);
		set<int> set;
		store(root, set);
		auto it = set.begin();
		convert(root, it);
		inorder(root);
		cout << endl;
	}
}

