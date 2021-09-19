#include <iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int n;
void solve(int size) {
	if (size == 0) {//3의 0승되면
		cout << "-";
		return;
	}
	solve(size - 1);
	for (int i = 0; i < pow(3, size - 1); i++) {
		cout << " ";
	}
	solve(size - 1);
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	while (1) {
		cin >> n;
		if (cin.eof())break;
		solve(n);
		cout << "\n";
	}
	return 0;
}
