#include<iostream>
#define MAX 29
using namespace std;

//MAX를 29로 정해주는 이유는 -14~14까지 해야 하기 때문이다.

int N;
double Percent[4];
bool Visit[MAX][MAX];

int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };
//각각 방향을 정해준다.

double DFS(int x, int y, int Cnt)
{
	if (Cnt == N) return 1.0;
	//Cnt==n이면 1을 반환해준다.

	Visit[x][y] = true;
	double Result = 0.0;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		//여기서 방향대로 들어가게 된다.

		if (Visit[nx][ny] == true) continue;
		Result += Percent[i] * DFS(nx, ny, Cnt + 1);
		//recursion 방식으로 Result에 더해준다.
	}

	Visit[x][y] = false;
	return Result;
}

int main()
{
	double R;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//속도를 빠르게 하기 위함이다.
	cin >> N;
	for (int i = 0; i < 4; i++)
	{
		int a; cin >> a;
		Percent[i] = a / 100.0;
	}
	//Percent[i]에 각각 확률을 넣어준다.

	R = DFS(14, 14, 0);

	cout.precision(10);
	cout << fixed << R << "\n";
	//10^(-9)자리까지 print하라고 했으니 그렇게 해준다.

	return 0;
}
