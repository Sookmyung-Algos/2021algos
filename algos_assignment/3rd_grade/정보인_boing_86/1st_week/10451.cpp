#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int ans = 0;
int arr[1001];
bool v[1001];

void fuct(int node1) {
	int node2 = arr[node1];
	v[node1] = true;

	if (v[node2] == false) {
		fuct(node2);
	}

	else {
		ans++;
	}

}

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		for (int j = 1; j <= n; j++) {
			cin >> arr[j];
		}

		for (int k = 1; k <= n; k++) {
			if (v[k] == false) {
				fuct(k);
			}
		}
		cout << ans << endl;

		ans = 0;
		memset(arr, 0, 1001*sizeof(int));
		memset(v, false, 1001);
	}
}
