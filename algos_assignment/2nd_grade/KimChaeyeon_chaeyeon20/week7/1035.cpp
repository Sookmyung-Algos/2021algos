#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#define MAX 987654321
using namespace std;
 
int len;
int result = MAX;
bool visit[7][7];
char map[7][7];
int moveX[4] = { 0, 1, 0, -1 };
int moveY[4] = { 1, 0, -1, 0 };
vector<pair<int, int> > v;
 
int calc(int a, int b, int c, int d)
{
	return abs(a - c) + abs(b - d);
}
 
void check(int a, int b)
{
	for (int i = 0; i < 4; ++i) {
		int x = b + moveX[i];
		int y = a + moveY[i];
 
		if (map[y][x] != '*' || visit[y][x]) {
			continue;
		}
		visit[y][x] = true;
 
		check(y, x);
	}
}
 
bool connect() {
	int c = 0;
 
	memset(visit, 0, sizeof(visit));
	for (int i = 1; i <= 5; ++i) {
		for (int j = 1; j <= 5; ++j) {
			if (map[i][j] == '*' && !visit[i][j]) {
				visit[i][j] = 1;
				++c;
				check(i, j);
			}
		}
	}
 
	if (c == 1) {
		return true;
	}
	else {
		return false;
	}
}
 
void DFS(int c, int d)
{
	if (d >= result) {
		return;
	}
 
	if (c == len) {
		if (connect()) {
			result = min(result, d);
		}
		return;
	}
 
	for (int i = 1; i <= 5; ++i) {
		for (int j = 1; j <= 5; ++j) {
			if (map[i][j] == '.') {
				map[i][j] = '*';
				DFS(c + 1, d + calc(v[c].first, v[c].second, i, j));
				map[i][j] = '.';
			}
		}
	}
}
 
int main(int argc, char * argv[])
{
	string s;
 
	memset(map, ' ', sizeof(map));
	for (int i = 1; i <= 5; ++i) {
		for (int j = 1; j <= 5; ++j) {
			cin >> map[i][j];
			if (map[i][j] == '*') {
				v.push_back(make_pair(i, j));
				map[i][j] = '.';
			}
		}
	}
 
	len = v.size();
	DFS(0, 0);
 
	cout << result << endl;
 
	return 0;
}
