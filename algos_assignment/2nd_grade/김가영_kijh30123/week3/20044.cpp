#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int n, a;
vector<int>v;
int main() {
	cin >> n;
	n *= 2;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	a = 1234567891;
	for (int i= 0; i < n; i++) {
		a = min(a, v[i] + v[n - 1 - i]);
	}
	cout << a;
}
