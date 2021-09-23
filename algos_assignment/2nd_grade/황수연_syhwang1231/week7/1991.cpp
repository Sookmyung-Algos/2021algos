// 1991: 트리 순회(Silver 1)
#include <iostream>
#include <vector>
using namespace std;

int n;
char a, b, c;
vector<vector<int>> tree;
vector<int> parent;
vector<int> v;

void preOrder(int root) {
	cout << (char)(root + 'A');

	if (tree[root][0] != -1)
		preOrder(tree[root][0]);
	if (tree[root][1] != -1)
		preOrder(tree[root][1]);
	return;
}

void inOrder(int root) {
	if (tree[root][0] != -1)
		inOrder(tree[root][0]);
	cout << (char)(root + 'A');
	if (tree[root][1] != -1)
		inOrder(tree[root][1]);
}

void postOrder(int root) {
	if (tree[root][0] != -1)
		postOrder(tree[root][0]);
	if (tree[root][1] != -1)
		postOrder(tree[root][1]);
	cout << (char)(root + 'A');
}

int main(void) {
	cin >> n;
	parent.resize(n);
	for (int i = 0; i < n; i++)
		tree.push_back(v);

	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		if (b == '.')
			tree[a - 'A'].push_back(-1);
		else
			tree[a - 'A'].push_back(b - 'A');
		if (c == '.')
			tree[a - 'A'].push_back(-1);
		else
			tree[a - 'A'].push_back(c - 'A');
	}

	preOrder(0);
	cout << "\n";
	inOrder(0);
	cout << "\n";
	postOrder(0);
	cout << "\n";
	return 0;
}
