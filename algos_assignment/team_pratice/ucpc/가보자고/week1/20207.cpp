// baekjoon 20207 달력

#include <iostream>
#include <cstring>
#include <map>
#include <unordered_map>
#include <string>
#include <vector>
#include <queue>
#include <algorithm> 
#define MAX 10001
using namespace std;

bool compare(pair<int, int> a, pair <int, int>b) {
	if (a.first == b.first)
		return a.second < b.second;  // 오름 차순
	return
		a.first < b.first;
}
int main(void) {
	int n;
	cin >> n;
	vector <pair<int, int>> sch;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		sch.push_back({ a,b });
	}
	sort(sch.begin(), sch.end());

	int start = 0;  //코팅지 시작 지점(가로)
	int end = 0; //코팅지 끝 지점(가로)
	int rowend[1003] = { 0 }; //코팅지 세로로 끝 지점   row[1]:위에서 1번째 줄 의 끝 지점 들어감
	int row = 1;
	int cnt = 0;
	int flag = 0;

	for (int i = 0; i < n; i++) {
		flag = 0;
		if (sch[i].first >= end + 2 && i != 0) {  //코팅지 끊기고 새로 시작
			int co = row * (end - start + 1);     //코팅지 넓이
			cnt += co;

			start = 0, end = 0, row = 1;
			memset(rowend, 0, 4 * 1003);
		}
		if (start == 0) {   //새로 시작
			start = sch[i].first;

		}
		if (sch[i].second > end) end = sch[i].second;   //가로로 끝나는 지점

		for (int j = 1; j <= row; j++) {
			if (rowend[j] < sch[i].first) {
				rowend[j] = sch[i].second;
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			row++;
			rowend[row] = sch[i].second;
		}
	}
	int co = row * (end - start + 1);
	cnt += co;
	cout << cnt;
	return 0;
}
