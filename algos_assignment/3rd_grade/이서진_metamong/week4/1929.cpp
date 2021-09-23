#include<bits/stdc++.h>
using  namespace std;
int cnt = 0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	int sum = 0;
	int min = 10001;
	if (n == 1) n += 1;
	for (int i = n; i <= m; i++) {
		bool ch = true;
		for (int j = 2; j * j <= i; j++) {
			if (i == 2) {
				min = 2;
				sum == 2;
				break;
			}
			else if (i % j == 0) {
				ch = false;
				break;
			}
		}
		if (ch == true) {
			cout << i<<"\n";
			if (i < min) min = i;
		}
	}
}
