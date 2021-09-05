#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long int n;
int temp;
int End;;
vector <int> v;
int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		v.push_back(temp);
	}
	cin >> End;
	temp = n / End;
	for (auto it = v.begin(); it != v.end();) {
		sort(it, it + temp);
		it += temp;
	}
	for (int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}
}
