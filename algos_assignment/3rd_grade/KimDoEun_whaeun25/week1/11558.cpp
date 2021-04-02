#include<iostream>
#include<vector>

using namespace std;

int main() {

	int testcase;

	cin >> testcase;

	for (int t = 0; t < testcase; t++) {
		int n, count = 0;
		bool check = false;
		vector<int>game;

		cin >> n;

		game.push_back(0);

		for (int i = 0; i < n; i++) {
			int a;

			cin >> a;

			game.push_back(a);

		}

		int next = 1;

		while (next != n) {
			next = game[next];
			count++;
			if (count > n) {
				check = true;
				break;
			}
		}

		if (check) {
			cout << "0" << "\n";
		}
		else {
			cout << count << "\n";
		}
	}

}
