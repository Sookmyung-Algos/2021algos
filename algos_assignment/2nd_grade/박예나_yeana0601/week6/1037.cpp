#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, temp;
vector<int> divisor;

int main() {
	ios::sync_with_stdio;
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		divisor.push_back(temp);
	}
	sort(divisor.begin(), divisor.end());
	cout << divisor.front() * divisor.back();
}
