#include <iostream>
#include<list>
using namespace std;
int main() {
	list<int> l;

	int sum=0,n,m,cnt=0;
	cin >> n;
	cin >> m;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		l.push_back(k);
	}
	auto a= l.begin();
	auto b = a;
	while (a != l.end()) {
		if (sum > m || b == l.end()) {
			sum -= *a;
			a++;
		}
		else {
			sum += *b;
			b++;
		}
		if (sum == m) {
			cnt++;
		}
	}
	cout << cnt;
}
