#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

void moo(int k, int mid, int len) {
	int total_len = len * 2 + mid + 3;
	if (k <= 3) {   //3이하면 s(0)에서 해결가능
		if (k == 1)
			cout << "m";
		else
			cout << "o";
		exit(0);
	}

	if (k > total_len)   //k가 수열의 길이보다 크면 추가해줌
		moo(k, mid + 1, total_len);
	else {
		if (k <= len + mid + 3 && k > len) {   //mooo...부분이면
			if (k - len == 1)
				cout << "m";
			else
				cout << "o";
			exit(0);
		}
		else
			moo(k-(len+mid+3), 1, 3);
	}
}

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	moo(n, 1, 3);
}
