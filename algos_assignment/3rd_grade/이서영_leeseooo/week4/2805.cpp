#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<memory.h>
#include<queue>
using namespace std;
int n, m;
int maxTree = 0;
vector<int>tree;
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		if (maxTree < tmp) maxTree = tmp;
		tree.push_back(tmp);
	}
	long low = 0, high = maxTree;
	long ans = 0;
	while (high >= low) {
		long mid = (low + high) / 2;
		long cut = 0;
		for (int i = 0; i < tree.size(); i++) {
			if(tree[i] >= mid)
				cut += tree[i] - mid;
		}
		if (cut >= m) {
			low = mid + 1;
			ans = max(ans, mid);
		}
		else if (cut < m) {
			high = mid-1;
		}
	}
	cout << ans;
}
