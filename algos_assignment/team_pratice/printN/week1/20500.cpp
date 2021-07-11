#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
int MOD = 1000000007;

int main(void)
{
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL); //입출력속도 개선
	
	vector<vector<int> > v1(1516, vector<int>(1516, 0));

	cin >> N;
	v1[0][1] = 0;
	v1[0][2] = 1;
	v1[1][2] = 1;
	v1[2][2] = 0;

	if (N <= 2) {
		cout << v1[0][N];
	}
	else {
		for (int i = 3; i < N + 1; i++) { //3의 배수인지만 확인, 끝자리 5라고 가정가능
			v1[0][i] = (v1[1][i - 1] + v1[2][i - 1]) % MOD; //3의 배수가 될수있는 경우의 수 다음 행에 더하기
			v1[1][i] = (v1[0][i - 1] + v1[2][i - 1]) % MOD; //값이 매우 커지므로 계속 나눠주기
			v1[2][i] = (v1[0][i - 1] + v1[1][i - 1]) % MOD;
		}
		cout << v1[0][N];
	}
	return 0;
}
