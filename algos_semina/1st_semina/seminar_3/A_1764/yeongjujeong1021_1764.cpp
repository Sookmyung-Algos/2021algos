#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int n, m, cnt = 0;
	cin >> n >> m;
	string* a = new string[n + m];
	string* b = new string[n + m];
  
	for (int i = 0; i < n + m; i++)
		cin >> a[i];
  
	sort(a, a + n + m);
  
	for (int i = 1; i < n + m; i++) {
		if (!(a[i].compare(a[i - 1])))
			b[cnt++] = a[i];
	}
  
	cout << cnt << '\n';
	for (int i = 0; i < cnt; i++)
		cout << b[i] << '\n';
  
	return 0;
}
