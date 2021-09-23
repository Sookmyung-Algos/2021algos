#include <iostream>
#include <list>
using namespace std;
int main() {
	int n, k;
	cin >> n>>k;
	list<int> num;
	int i=n, cnt=1;
	while (i) {
		num.push_front(i--);
	}
	auto p = num.begin();
	cout << "<";
	while (num.size()!=1) {
		for (int i = 0; i < k - 1; i++) {
			p++;
			if (p == num.end()) {
				p = num.begin();
			}
		}
		cout << *p << ", ";
		p = num.erase(p);
		if (p == num.end()) {
			p = num.begin();
		}
	}
	cout <<*p<< ">";
}
