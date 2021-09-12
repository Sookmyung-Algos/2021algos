#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

vector<int> num;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a, p, answer;
	int sum = 0;

	cin >> a >> p;

	int check = 0;

	num.push_back(a);

	while (!check) {
		
		int next = a;
		sum = 0;

		while (next != 0) {
			sum += pow(next % 10, p);
			next /= 10;
		}

		num.push_back(sum);

		for (int i = 0; i < num.size() - 1; i++) {
			if (num[i] == sum) {
				check = 1;
				answer = i;
				break;
			}
		}

		a = sum;
	}

	cout << answer;

}
