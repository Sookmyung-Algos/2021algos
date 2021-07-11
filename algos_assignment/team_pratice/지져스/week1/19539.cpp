#include<iostream>
using namespace std;

int num, total, up2 ;

int main() {
	cin >> num;
	for (int i = 0; i < num; i++) {
		int x;
		cin >> x;
		total += x;
		up2 += (x / 2);
	}

	if (total % 3 == 0) {
		if ( up2 >= ( total / 3)) {
			cout << "YES\n";
			return 0;
		}
		else {
			cout << "NO\n";
			return 0;
		}
	}
	else {
		cout << "NO\n";
	}
}
