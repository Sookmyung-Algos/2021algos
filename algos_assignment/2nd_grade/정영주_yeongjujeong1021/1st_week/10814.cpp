#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100000

struct member {
	int age;
	string name;
	int join;
} m[MAX];

bool f(member a, member b) {
	if (a.age == b.age) return a.join < b.join;
	else return a.age < b.age;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m[i].age >> m[i].name;
		m[i].join = i;
	}
	sort(m, m + n, f);
	for (int i = 0; i < n; i++)
		cout << m[i].age << ' ' << m[i].name << '\n';
	return 0;
}
