#include <iostream>

using namespace std;

int main(void)
{
	int n, m;	//n은 수열의 원소 개수, m은 수열의 합
	int num[10001];

	cin >> n >> m;

	for (int i = 0; i < n; i++)		//n개의 수 입력받기
	{
		cin >> num[i];
	}

	int s = 0, e = 0;	//투포인터 사용, s는 시작 위치, e는 끝 위치
	int sum = 0, count = 0;	//합과 개수는 0으로 초기화

	while (s < n)
	{
		if (sum == m)	//합이 m과 같으면 count 증가
			count++;

		if (sum >= m)	//합이 m이상이면 num[s]빼고 s는 증가
			sum -= num[s++];
		else if (e == n)	//sum이 m미만인데 e가 n과 같으면 더이상 진행X
			break;
		else	//sum이 m미만, e가 n 미만인 경우 e번째 원소 더하고 e 증가
			sum += num[e++];
	}
	cout << count;
	return 0;
}
