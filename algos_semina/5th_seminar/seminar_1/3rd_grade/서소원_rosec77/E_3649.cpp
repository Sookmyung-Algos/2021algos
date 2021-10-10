#include <iostream>
#include <algorithm>
using namespace std;
int piece[1000002];
int main() {

	int x, n, front, back, over;

	while (1) {
		cin >> x >> n;
		if (cin.eof()) break;
		x = x * 10000000;

		for (int i = 0; i < n; i++) {
			cin >> piece[i];
		}
		sort(piece, piece + n);

		front = 0, back = n - 1, over = 0;
		while (front < back) {
			if (piece[front] + piece[back] > x)
				back--;
			else if (piece[front] + piece[back] < x)
				front++;
			else {
				cout << "yes " << piece[front] << " " << piece[back] << '\n';
				over = 1;
				break;
			}
		}
		if (over == 0)
			cout << "danger" << '\n';
	}
}
