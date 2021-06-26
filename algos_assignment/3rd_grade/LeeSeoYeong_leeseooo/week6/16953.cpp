#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<algorithm>
using namespace std;
int main() {
	int a, b;
	int cnt = 1;
	cin >> a >> b;
	while (b > a) {
		if (b % 2 == 0) {
			b /= 2;
			cnt++;
		}
		else if(b % 10 == 1){// b % 2 == 1 로 해버리면 1로 13을 만들수 있게됨. 1의자리 1일때만 처리
			b /= 10;
			cnt++;
		}
		else { // 1의자리 3 7 오는 경우 처리 안해주면 무한루프
			cout << "-1";
			break;
		}
	}
	if (a > b) {
		cout << "-1";
	}
	if (a == b) {
		cout << cnt;
	}
}
