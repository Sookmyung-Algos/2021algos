#include <iostream>
#include <map>
using namespace std;

int main() {
	string s, a[7] = {"Re","Pt","Cc","Ea","Tb","Cm","Ex"};
	map<string, int> m;
	for (auto i: a)
		m.insert({i, 0});
	int sum = 0;
	while (cin >> s) {
		m[s]++;
		sum++;
	}
	cout << fixed; cout.precision(2);
	for (auto i: a)
		cout << i << " " << m[i] << " " << (double) m[i] / sum << "\n";
	cout << "Total " << sum << " 1.00";
	return 0;
}
