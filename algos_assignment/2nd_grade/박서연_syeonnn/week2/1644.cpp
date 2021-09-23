#include <iostream>
#include <vector>

using namespace std;

int arr[4000001];
int num;
vector <int> prime;

int main() {
	cin >> num;

	// 에라토스테네스의 체
	// 입력받은 수 num 만큼 배열에 초기화
	for (int i = 2; i <= num; i++) {
		arr[i] = i;
	}

	for (int i = 2; i <= num; i++) {
		if (arr[i] == 0)
			continue;
		for (int j = i + i; j <= num; j += i) {
			arr[j] = 0; 
		} // i를 제외한 i의 배수들은 소수가 아니므로 0으로 바꾸기
	}

	for (int i = 2; i <= num; i++) {
		if (arr[i] != 0) {
			prime.push_back(i); 
		} // 벡터 prime에 소수 저장
	}

	int l = 0, r = 0;
	int cnt = 0, sum = 0;

	while (1) {
		if (sum >= num) sum -= prime[l++]; // 부분 합이 num 보다 크거나 같으면 가장 왼쪽의 수 빼기
		else if (r == prime.size()) break; // 마지막 인덱스에 도달하면 멈추기
		else sum += prime[r++]; // 부분 합이 num 보다 작으면 가장 오른쪽의 수 더하기

		if (sum == num) cnt++; // 부분 합과 num이 같으면 cnt 1씩 증가
	}
	cout << cnt;
	return 0;
}
