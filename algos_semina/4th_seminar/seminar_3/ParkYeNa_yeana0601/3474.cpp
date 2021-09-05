// 2, 5 소인수분해 했을 시 적은 쪽
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long int n;

int temp;
int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		int two = 0;
		int five = 0;
		for (int j = 2; j <= temp; j *= 2) {
			two += temp / j;
		}
		for (int k = 5; k <= temp; k *= 5) {
			five += temp / k;
		}
		cout << min(two, five) << "\n";
	}


}
