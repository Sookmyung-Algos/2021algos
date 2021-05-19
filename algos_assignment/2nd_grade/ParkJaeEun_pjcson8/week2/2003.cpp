#include <iostream>

using namespace std;

int main() {

    int N, M;
    int num[10001];
    int s = 0, e = 0, count = 0, sum = 0;

    cin >> N >> M; //N,M 입력받기.

    for (int i = 0; i < N; i++)
        cin >> num[i];        

	while (s < N)
	{
		if (sum >= M || e == N)	//합이 M이상 또는 e와 N이 같을 경우
			sum -= num[s++];

		else	//합이 M미만, e가 N 미만인 경우
			sum += num[e++];

		if (sum == M)	//합이 M과 같은 경우
			count++;
	}
	cout << count << '\n';

	return 0;
}
