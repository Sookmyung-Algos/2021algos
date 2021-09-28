#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main() {

	int n, origin;
	int cycle = 1;

	cin >> n;
	origin = n;

	while (1) {
		int front, back;
		int front2, back2;
		int sum;

		if (n < 10) {
			front = 0;
			back = n;
		}
		else {
			front = n / 10;
			back = n % 10;
		}

		sum = front + back;

		if (sum < 10) {
			front2 = 0;
			back2 = sum;
		}
		else {
			front2 = sum / 10;
			back2 = sum % 10;
		}

		n = 10 * back + back2;

		if (origin == n) {
			break;
		}
		cycle++;
	}

	cout << cycle;

}
