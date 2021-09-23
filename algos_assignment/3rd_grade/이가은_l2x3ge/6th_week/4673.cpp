#include <iostream>
using namespace std;

int nextNum(int x);
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	bool n[10001] = { false, };
	for (int i = 1; i <= 10000;i++) {
		if (n[i] == true)
			continue;

		int tmp = nextNum(i);
		while (tmp<=10000) {
			n[tmp] = true;
			tmp = nextNum(tmp);
		}
	}
	for (int i = 1; i <= 10000;i++) {
		if (n[i] == false)
			cout << i << "\n";
	}
	return 0;
}

int nextNum(int num) {
	int x = num;
	int result = 0;
	while (x) {
		result += x % 10;
		x /= 10;
	}
	return result + num;
}
