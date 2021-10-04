#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int map[101][101];
int N, K, L, T;
int now_d = 1;
deque<pair<int, int>> snake;
vector<pair<int, char>> v;
int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, +1, 0, -1 };
bool getAns;

bool move() {
   int x = snake.front().first;
   int y = snake.front().second;
   int nx = x + dx[now_d];
   int ny = y + dy[now_d];
   if (map[nx][ny] == -1  nx < 1  nx > N  ny < 1  ny > N) {
      return false;
   }
