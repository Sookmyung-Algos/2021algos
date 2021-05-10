#include<iostream>
#include<algorithm>
using namespace std;

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}

int main() {
	int N1, N2, N3, N4, N5;
	cin >> N1 >> N2 >> N3 >> N4 >> N5;
	int max = 1000000;
	for (int i = 1; i <= max; i++) {
		int count = 0;
		if (i%N1 == 0) {
			count++;
		}
		if (i%N2 == 0) {
			count++;
		}
		if (i%N3 == 0) {
			count++;
		}
		if (i%N4 == 0) {
			count++;
		}
		if (i%N5 == 0) {
			count++;
		} 
		if (count >= 3) {
			cout << i;
			break;
		}
	}
	return 0;
}
