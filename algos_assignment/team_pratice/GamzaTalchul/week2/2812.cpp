#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
deque <char> d;
int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	string num;
	cin >> n >> k;
	cin >> num;    //visual studio 2015에서는 에러로 나옴.
	for (int i = 0; i < n; i++) {
		while (!d.empty() && k&& d.back() < num[i]) {
			d.pop_back();
			k--;   
		}
		d.push_back(num[i]);
	}
	for (int i = 0; i < d.size() - k; i++)  //deque는 pop_back을 한다고 size가 줄어들지 않음.
		cout << d[i];
}
