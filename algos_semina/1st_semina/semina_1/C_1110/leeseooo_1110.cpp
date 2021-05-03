#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
using namespace std;
int main() {
	int n, cnt=0, tmp=0;
	cin >> n;
	tmp = n;
	while (1) {
		cnt++;
		int a, b;
		a = tmp / 10 + tmp % 10;
		b = a % 10 + (tmp % 10 * 10); //새로운 수
		if (b == n) {
			break;
		}
		tmp = b;
	}
	cout << cnt;
}
