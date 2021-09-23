#include <iostream>
using namespace std;

#define MAX 29 // N <= 14

int N;
double Percent[4];
bool Visit[MAX][MAX];

int dx[] = { 0, 0, 1, -1 }; // 동, 서, 남, 북
int dy[] = { 1, -1, 0, 0 };

double DFS(int x, int y, int Cnt)
{
	if (Cnt == N) return 1.0;

	Visit[x][y] = true; // 방문한 곳은 true 표시
	double Result = 0.0;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (Visit[nx][ny] == true) continue; // 이미 방문했던 곳은 이동 경로가 단순하지 않음 따라서 확률 계산에서 제외함
		Result = Result + Percent[i] * DFS(nx, ny, Cnt + 1); // 입력 받았던 각 방향별 확률만큼 곱해서 확률 계산
	}
	
	Visit[x][y] = false;
	return Result;
}

int main()
{
	cin >> N; // 이동 횟수

	for (int i = 0; i < 4; i++) // 방향별 확률 입력 받아 Percent 배열에 저장
	{
		int a; 
		cin >> a;
		Percent[i] = a / 100.0;
	}

	double R = DFS(14, 14, 0); // 시작좌표(14, 14) (0~13, 14, 15~28), 시작횟수 0회
	cout.precision(10); // 오차범위를 10^-9까지 허용하기에 10^-10까지 출력하도록 소수점 고정
	cout << fixed << R << endl;

	return 0;
}
