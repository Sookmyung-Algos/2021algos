#include <iostream>
using namespace std;

int main() {
	int n,cnt=0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		if (i % 5 == 0)cnt++;
		if (i % 25 == 0)cnt++;
		if (i % 125 == 0)cnt++;
	}
	cout << cnt<<endl;
	return 0;
}
