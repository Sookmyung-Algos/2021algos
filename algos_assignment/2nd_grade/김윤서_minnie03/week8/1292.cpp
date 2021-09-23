#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int num[2001] = { 0, };
	int a, b;
	cin >> a >> b;

	int k = 1,m=1; //k는 인덱스, m은 1씩 커지는 정수
	while (k <= b) { //b번째 원소까지
		for (int i = 0; i < m; i++) { //정수 m개만큼
			num[k++] = m; //배열 원소의 값을 m으로 저장
		}
		m++; 
	}

	int sum = 0;
	int n = a; //a 인덱스부터 시작
	while (n <= b) { //b 인덱스까지
		sum += num[n++]; //sum에 각 num값을 더함
	}

	cout << sum << endl; //구간에 속하는 숫자의 합 출력
	return 0;
}
