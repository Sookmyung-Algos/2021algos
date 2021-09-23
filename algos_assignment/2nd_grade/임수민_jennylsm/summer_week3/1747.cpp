#include <iostream>
using namespace std;

int check[10000001];
int N;
void find() {
	for (int i = 2; i <= 10000000; i++) {
		check[i] = i;
	}
	for (int i = 2; i <= 10000000; i++) {
		if (check[i] == 0) continue;
		for (int j = i + i; j <= 10000000; j += i) {
			check[j] = 0;
		}
	}
}
bool pelindrome(int num) { //대칭인지 아닌지 판단하는 함수
	int temp = num;
	int arr[10];
	int i = 0;
	while (1) {
		arr[i] = temp % 10;
		temp /= 10;
		if (temp == 0) break;
		i++;
	}

	for (int j = 0; j <= i / 2; j++) {
		if (arr[j] != arr[i - j]) return false;
	}
	return true;
}
int main(void) {
	cin >> N;
	find();
	int ans;
	for (int i = N; i <= 10000000; i++) {
		if (check[i] != 0 && pelindrome(i)) {
			ans = i;
			break;
		}
	}
	cout << ans << '\n';
	return 0;
}
