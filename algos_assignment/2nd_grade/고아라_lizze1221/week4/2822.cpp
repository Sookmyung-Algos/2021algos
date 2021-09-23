#include <iostream>
using namespace std;

int main() {

	int score[9];
	int sum = 0;

	for (int i = 0; i < 8; i++){
		cin >> score[i];
		sum = sum + score[i];
	}

	score[8] = 150;

	int min = 8;
	for (int i = 0; i < 3; i++) {

		for (int j = 0; j < 8; j++) {
			if (score[j] != -1) {
				if (score[min] > score[j]) min = j;
			}
		}

		sum = sum - score[min];
		score[min] = -1;
		min = 8;
	}


	cout << sum << "\n";
	for (int i = 0; i < 8; i++) {
		if (score[i] != -1)
			cout << i + 1 << " ";
	}

	return 0;
}
