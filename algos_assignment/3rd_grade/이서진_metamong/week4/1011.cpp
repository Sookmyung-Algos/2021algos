#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	double x, y;
	vector<int> v;
	cin >> t;
	while (t--) {
		double i = 1, cnt = 0;
		cin >> x >> y;	
		for (;; i++) {
			if (i * i > y - x)
				break;
		}
		if ((i - 1) * (i - 1) == y - x)
			cnt = 2 * (i - 1) - 1;
		else if ((i - 1) * (i - 1) + ((i * i - (i - 1) * (i - 1)) / 2) >= y - x)
			cnt = 2 * i - 2;
		else
			cnt = 2 * i - 1;
		v.push_back(cnt);
	}
	for (vector<int>::iterator i = v.begin(); i < v.end(); i++)
		cout << *i <<"\n";
}
