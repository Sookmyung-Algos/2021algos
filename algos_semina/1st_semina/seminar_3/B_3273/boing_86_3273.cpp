#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);

	int n, m, x, a, b;
	int count = 0;
	int sum;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> m;
		v.push_back(m);
	}
	
	cin >> x;
	sort(v.begin(), v.end());
	a = 0;
	b = v.size()-1;

	while (1) {

		if (a >= b)
			break;

		sum = v[a] + v[b];

		if (sum == x) {
			a++;
			b--;
			count++;
		}

		else if (sum < x) {
			a++;
		}

		else if (sum > x) {
			b--;
		}
	}

	cout << count;

}
