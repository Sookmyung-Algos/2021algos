#include <iostream>
#include <algorithm>
using namespace std;

long long N;

int main() {

	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;

	long long total=0, maxnum=0;
	for (int i = 0; i < N; i++) {
		long long input; cin >> input;
		if (i == 0)
			maxnum = input;
		total = total + input; // 전체 합
		if (input > maxnum)
			maxnum = input;
	}

	if (total - maxnum >= maxnum) { // 가장 큰수 빼고 나머지가 가장큰수 보다 크다면
		if (total % 2 == 0) // 짝수
			cout << 0 << "\n";
		else // 홀수
			cout << 1 << "\n";
	}
	else { // 가장 긴 데서 나머지 빼기
		cout << maxnum - (total - maxnum) << "\n";
	}
	return 0;
}
