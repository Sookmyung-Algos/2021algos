#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v;
int del, answer = 0;

void leaf_count(int node) {
	if (node == del) return;
	int size = v[node].size();
	switch (size) {
		case 0: answer++; return;
		case 1: if (v[node][0] == del) {
			answer++; break;
		}
		default: 
			for (int i = 0; i < size; i++)
				leaf_count(v[node][i]);
			break;
	}
}

int main() {
	int n, parent, root;
	cin >> n;
	v.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> parent;
		if (parent != -1) v[parent].push_back(i);
		else root = i;
	}

	cin >> del;
	leaf_count(root);
	cout << answer;
}
