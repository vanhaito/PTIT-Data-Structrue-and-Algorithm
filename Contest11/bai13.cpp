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
bool isEqualTrees(Node *root1, Node *root2){
	if (root1==NULL && root2==NULL)
		return true;
	if (root1!=NULL && root2!=NULL)
		return(root1->data==root2->data && isEqualTrees(root1->left, root2->left)
		 && isEqualTrees(root1->right, root2->right));
	return false;
}
int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		Node *root1 = ConstructTree(n);
		int m; cin >> m;
		Node *root2 = ConstructTree(m);
		if (isEqualTrees(root1, root2))
			cout << 1;
		else 
			cout << 0;
		cout << endl;
	}
}
