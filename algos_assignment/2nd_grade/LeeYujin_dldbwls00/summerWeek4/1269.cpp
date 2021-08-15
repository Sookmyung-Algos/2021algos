#include <iostream>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int a, b;
	cin >> a >> b;
	set<int> s; 
	set<int>::iterator it;
	for (int i = 0; i < a; i++) {
		int temp;
		cin >> temp;
		s.insert(temp);
	}
	int cnt = 0;
	for (int i = 0; i < b; i++) {
		int temp;
		cin >> temp;
		it = s.find(temp);
		if (it != s.end())	cnt++;
	}
	
	cout << a + b - cnt * 2;
	return 0;
}
