#include <iostream>

using namespace std;
long a, b, c;

int solve(long num, long k) // 재귀 함수
{
	if (k == 1) return num % c;// 주어진 지수가 1인 경우는 바로 C로 나눈 값 반환
	long newNum = solve(num, k / 2); // 지수가 1이 될 때까지 재귀적으로 수행
	if (k % 2 == 1) return (newNum * newNum % c) * num % c; // 지수가 홀수인 경우 
	return newNum * newNum % c; // 지수가 짝수인 경우
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> a >> b >> c;
	cout << solve(a, b);
	return 0;
}
