#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
#include <algorithm> 
#include <queue>

#include <time.h>
#define MAX 100001
using namespace std;

int n, k;  //큐브의 개수 N과 스위치의 개수 K
//int cube[9]; //큡의 숫자 저장
vector <int> cube;
vector <vector<int>> swi;
//vector <vector<int>> cubeswi;  //큐브마다 연결된 스위치 저장
vector<int> pushh(vector <int> now, int num) {
	vector <int> ret = now;
	int size = swi[num].size();
	for (int i = 0; i < size; i++) {
		int a = swi[num][i];
		ret[a - 1] += num + 1;
		ret[a - 1] %= 5;

	}
	return ret;
}
int isSame(vector <int> now) {
	int size = now.size();
	int a = now[0];
	for (int i = 1; i < size; i++) {
		if (a != now[i]) return 1;
	}
	return 0;
}
int bfs() {
	queue<vector <int>> qu;
	map<vector <int>, int> m;
	m[cube] = 0;
	qu.push(cube);

	while (!qu.empty()) {
		vector <int> now = qu.front();
		qu.pop();
		int retur=isSame(now);
		if (retur == 0) return m[now];
		int jj = m[now];
		for (int i = 0; i < swi.size(); i++) {
			vector <int> haha=pushh(now,i);
			if (m.find(haha) == m.end()) {
				m[haha] = jj + 1;
				qu.push(haha);
			}
		}

	}
	return -1;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> n >> k;
	//cubeswi.resize(n+1);
	swi.resize(k);
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		cube.push_back(a);
	}
	for (int i = 0; i < k; i++) {
		int a;
		cin >> a;
		for (int j = 0; j < a; j++) {
			int b;
			cin >> b;
			//cubeswi[b].push_back(i + 1);
			swi[i].push_back(b);
		}
	}
	cout<<bfs();
	return 0;
}
