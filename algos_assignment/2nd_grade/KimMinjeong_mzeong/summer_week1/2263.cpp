#include <iostream>
using namespace std;

int in[100001], post[100001];
int idx[100001];

void sol(int in_s, int in_e, int post_s, int post_e) {
	if (in_s > in_e || post_s > post_e) return;
	
	int root = post[post_e];
	cout << root << " ";
	
	sol(in_s, idx[root] - 1, post_s, post_s + (idx[root] - in_s) - 1); // 왼
	sol(idx[root] + 1, in_e, post_s + (idx[root] - in_s), post_e - 1); // 오
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> in[i];
	for (int i = 0; i < n; i++) cin >> post[i];
	for (int i = 0; i < n; i++) idx[in[i]] = i;

	sol(0, n - 1, 0, n - 1);

	return 0;
}
