#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX 25

int N;
int map[MAX][MAX];
bool check[MAX][MAX];
int cnt;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

vector <int> vec;

void DFS(int x, int y) {
	cnt++;
	check[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
		if (map[nx][ny] == 1 && check[nx][ny] == false) {
			DFS(nx, ny);
		}
	}
}	//DFS 탐색

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < N; j++)	
			map[i][j] = temp[j] - '0';
	}	//문자열을 숫자로 변환하여 저장

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1 && check[i][j] == false) {
				cnt = 0;
				DFS(i, j);
				vec.push_back(cnt);
			}
		}
	}	// DFS를 이용해 단지마다 집의 수를 세서 cnt로 저장, 벡터에 넣은 후 cnt를 0으로 초기화하여 재탐색

	sort(vec.begin(), vec.end());	//집의 수 오름차순 정렬
	cout << vec.size() << endl;	//단지 수

	for (int i = 0; i < vec.size(); i++) 
		cout << vec[i] << endl;

	return 0;
}
