#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
struct grade {
	string name;
	int ko;
	int en;
	int ma;
};
bool compare(grade g, grade n) {
	if (g.ko == n.ko and g.en == n.en and g.ma == n.ma) {
		return g.name < n.name;
	}
	if (g.ko == n.ko && g.en == n.en) {
		return g.ma > n.ma;
	}
	if (g.ko == n.ko) {
		return g.en < n.en;
	}
	
	else {
		return g.ko > n.ko;
	}
}
int main() {
	int n;
	cin >> n;
	vector<grade> g(n);
	for (int i = 0;i < n;i++) {
		cin >> g[i].name >> g[i].ko >> g[i].en >> g[i].ma;
	}
	sort(g.begin(), g.end(), compare);
	for (int i = 0;i < n;i++) {
		cout << g[i].name << '\n';
	}
}
