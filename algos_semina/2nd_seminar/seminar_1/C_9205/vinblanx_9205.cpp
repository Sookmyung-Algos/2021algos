#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
const int MAX = 102;
vector <int> graph[MAX];
bool visited[MAX];

void DFS(int now) {
	visited[now] = true;
	for (int i = 0; i < graph[now].size(); i++) {
		int next = graph[now][i];
		if (visited[next] == false)
			DFS(next);
	}
}

int distance(pair<int, int> p1, pair<int, int> p2) {
	return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int main() {
	int t, n;
	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		for (int j = 0; j < MAX; j++) {
			graph[j].clear();
			memset(visited, false, sizeof(visited));
		}

		scanf("%d", &n);
		vector<pair<int, int>> coor;

		for (int j = 0; j < n + 2; j++) {
			int x, y;
			cin >> y >> x;
			coor.push_back(make_pair(y, x));
		}

		for(int j = 0; j < n + 2; j++)
			for (int k = j + 1; k < n + 2; k++) {
				if (distance(coor[j], coor[k]) <= 1000) {
					graph[j].push_back(k);
					graph[k].push_back(j);
				}
			}

		DFS(0);

		if (visited[n + 1])
			printf("happy\n");
		else
			printf("sad\n");
	}

}
