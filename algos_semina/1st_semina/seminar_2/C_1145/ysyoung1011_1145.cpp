#include <iostream>
using namespace std;

int main() {
	int num[5], cnt = 0;
	for (int i = 0; i < 5; i++)
		cin >> num[i];
	for (int i = 1; ; i++) {
		
		for (int j = 0; j < 5; j++) {
			if (i%num[j] == 0) cnt++;
		}
		if (cnt >= 3) {
			cout << i; break;
		}
		else cnt = 0;
	}
}
