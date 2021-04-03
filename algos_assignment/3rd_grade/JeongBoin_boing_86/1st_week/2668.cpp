#include <iostream>
#include <algorithm>

using namespace std;

int ans = 0;
int narr[101];
bool v[101] = {false, };
bool f[101] = { false, } ;
int c[101];


void fuct(int node1) {
	int node2 = narr[node1];
	v[node1] = true;

	if (v[node2] == false) {
		fuct(node2);
	}

	else{
		if (f[node2] == false) {
			c[ans] = node1;
			ans++;
			for (int i = narr[node1]; i != node1; i = narr[i]) {
				c[ans] = i;
				ans++;
			}
		}
	}
	f[node1] = true;
}

int main() {
	int n;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> narr[i];
	}

	for (int j = 1; j <= n; j++) {
		if (v[j] == false) {
			fuct(j);
		}
	}

	cout << ans<<endl;
	sort(c, c + ans);
	for (int i = 0; i < ans; i++) {
		cout << c[i]<<endl;
	}
}
