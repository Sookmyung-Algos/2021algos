#include <iostream>
#include <algorithm>
using namespace std;

int arr[10];

int isPossible(int n) {
	if (n == 0) {
		if (arr[n]) return 0;
		else return 1;
	}
	int len = 0;
	while (n > 0) {
		if (arr[n % 10]) return 0;
		n /= 10;
		len++;
	} //고장난 버튼 있는지 확인
	return len;
}

int main(void) {
	int N, xNum;
	cin >> N >> xNum;
	for (int i = 0; i < xNum; i++) {
		int tmp;
		cin >> tmp;
		arr[tmp]++;
	}
	int ans = abs(N - 100);
	for (int i = 0; i <= 1000000; i++) { //채널이 500000까지 나오기 때문에 1000000까지로 설정함
		int move = 0;
		int len = isPossible(i); //고장난 버튼 확인
		if (len > 0) {
			move = abs(N - i) + len;
			ans = min(ans, move);
		}
	}
	cout << ans << "\n";
	return 0;
}
