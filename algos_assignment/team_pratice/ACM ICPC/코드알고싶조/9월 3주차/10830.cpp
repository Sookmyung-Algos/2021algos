#include <iostream>
#include <vector>

using namespace std;
int N; 
long long B;
typedef vector<vector<long long>> matrix; // 이중 vector 형태를 기본 행렬 구조로 지정
matrix arr;

matrix multi(matrix x1, matrix x2) // 행렬 곱셈 함수
{
	matrix newM(N, vector<long long>(N)); // 행렬 크기 지정
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			newM[i][j] = 0; // 0으로 초기화
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				newM[i][j] += (x1[i][k] * x2[k][j]) % 1000; // 각각의 위치에 행렬 곱셈을 수행하고 그 값을 1000으로 나눈 나머지를 저장함.
			}
			newM[i][j] = newM[i][j] % 1000;
		}
	}
	return newM; // 행렬 곱셈 결과가 저장된 새로운 행렬을 반환
}

matrix solve(matrix a, long long k)
{
	matrix temp(N, vector<long long>(N)); // 행렬 크기 지정
	for (int i = 0; i < N; i++) // 행렬 안에 저장된 값을 1로 초기화
		temp[i][i] = 1;
	while (k > 0) { // 지수가 0 이상일 때까지 반복
		if (k % 2 == 1) { // 지수가 홀수인 경우
			temp = multi(temp, a);
		}
		k /= 2;
		a = multi(a, a);
	}
	return temp;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> B;

	matrix A(N, vector<long long>(N)); // 행렬 크기 지정
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			cin >> A[i][j];

	arr = solve(A, B); // 함수의 반환값을 arr에 저장
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << arr[i][j] << " ";
		cout << "\n";
	}
	return 0;
}
