#include <iostream>
#define MAX 101
using namespace std;

//MAX를 101로 정해주는 이유는 처음 경우의 수를 제외하고 100개를 만들어야 하기 때문이다.

int N, K;
int Coin[MAX];
int DP[10001];


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//속도를 빠르게 하기 위함이다.
	
	cin >> N >> K;
	for (int i = 1; i <= N; i++) 
		cin >> Coin[i];
	//Coin에 값을 넣어준다.

	DP[0] = 1;
	//처음 경우의 수이다.
	for (int i = 1; i <= N; i++)
	{
		for (int j = Coin[i]; j <= K; j++)
		{
			DP[j] = DP[j] + DP[j - Coin[i]];
		}
	}
	//i=1인 이유는  처음 경우의 수를 넘기고 시작해야 하기 때문이다.

	cout << DP[K] << "\n";

	return 0;
}
