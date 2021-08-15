#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> v;

void seq(int cnt) {
	if (cnt == m) {
		for (int n : v) cout << n << " ";
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (v.empty()) v.push_back(i);
		else {
			if (v.back() <= i) v.push_back(i);
			else continue;
			}
		seq(cnt + 1);
		v.pop_back();
		}
	}
	

int main() {
	cin >> n >> m;
	seq(0);
}
