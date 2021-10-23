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
void solve(Node *root){
	stack<Node *> s1;	//right to left
	stack<Node *> s2;	//left to right
	s1.push(root);
	while (!s1.empty() || !s2.empty()){
		while (!s1.empty()){
			Node *temp = s1.top();
			s1.pop();
			cout << temp->data << " ";
			if (temp->right)
				s2.push(temp->right);
			if (temp->left)
				s2.push(temp->left);			
		}
		while (!s2.empty()){
			Node *temp = s2.top();
			s2.pop();
			cout << temp->data << " ";
			if (temp->left)
				s1.push(temp->left);
			if (temp->right)
				s1.push(temp->right);
		}
	}
}
int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		Node *root = ConstructTree(n);
		solve(root);	
		cout << endl;
	}
}
