#include <bits/stdc++.h>
#include <iostream>
using namespace std;
 
int n, k, q, m, x, s, e, add;
bool sleep[5005], check[5005];
vector<int> sum;
 
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k >> q >> m;
	sum.resize(n + 3, 0);
	for(int i=0; i<k; i++) {
		cin >> x;
		sleep[x] = 1;
	}
	for(int i=0; i<q; i++) {
		cin >> x;
		if (sleep[x]) continue;
		add = x;
		while (x <= n + 2) {
			if (sleep[x]) {
				x += add;
				continue;
			}
			check[x] = 1;
            x += add;
		}
	}
	for (int i = 3; i <= n + 2; i++)
        sum[i] = sum[i - 1] + (check[i] == 0);
	for (int i = 0; i < m; i++) {
		cin >> s >> e;
		cout << sum[e] - sum[s - 1] << '\n';
	}
}
