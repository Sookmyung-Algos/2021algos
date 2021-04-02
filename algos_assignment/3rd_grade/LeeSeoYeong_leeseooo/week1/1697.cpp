#include <iostream>
#include<queue>
#include<vector>
#include <algorithm>
using namespace std;
#define MAX 100001
int bfs(int N, int K);
int N, K;
int min;
bool visited[MAX] = { false, };
int main() {
	cin >> N >> K;
	cout << bfs(N,K);
}
int bfs(int N, int K) {
	queue<pair <int, int>>q;
	q.push(make_pair(N, 0));
	visited[N] = true;
	while (!q.empty()) {
		int X = q.front().first;
		int time = q.front().second;
		q.pop();
		if (X == K) return time;

		if (X + 1 < MAX && !visited[X + 1]) {
			q.push(make_pair(X + 1, time + 1));
			visited[X + 1] = true;
		}
		if (X - 1 >= 0 && !visited[X - 1]) {
			q.push(make_pair(X - 1, time + 1));
			visited[X - 1] = true;
		}
		if (X * 2 < MAX && !visited[X * 2]) {
			q.push(make_pair(X * 2, time + 1));
			visited[X * 2] = true;
		}
	}
}
