#include <iostream>
using namespace std;
int main() {
	int a[5];
	for (int i = 0; i < 5; i++) {
		cin >> a[i];
	}
	int x = 1;
	while (1) {
		int cnt = 0;
		for (int i = 0; i < 5; i++) {
			if (x % a[i] == 0) 
				cnt++;
		}
		if (cnt >= 3) 
			break;
		x++;
	}
	cout << x;
}
