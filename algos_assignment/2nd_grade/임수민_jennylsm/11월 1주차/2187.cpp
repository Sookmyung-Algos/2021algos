#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct {
	int row;
	int col;
	int weight;
}node;

bool comp(node a, node b) {
	if (a.row < b.row)
		return true;
	else if (a.row == b.row)
		return a.col < b.col;
	return false;
}

int max_weight(vector<node> point,int N, int A, int B) {

	int answer = 0;
	for (int i = 0; i < N; i++) {
		
		int min_num = point[i].weight;
		int max_num = point[i].weight;
		int x = point[i].row;
		int y = point[i].col;
		
		// 오른쪽
		for (int j = 0; j < N; j++) {
			if (i != j) {
				if (x + A > 2000000 || y + B > 2000000)
					continue;
				if ((x <= point[j].row) && (point[j].row < x + A) && (point[j].col >= y)&&(point[j].col < y + B)) {
					if (point[j].weight > max_num)
						max_num = point[j].weight;
					if (point[j].weight < min_num)
						min_num = point[j].weight;
				}
			}
		}
		if (max_num - min_num > answer)
			answer = max_num - min_num;
		// 왼쪽

		max_num = point[i].weight;
		min_num = point[i].weight;
		for (int j = 0; j < N; j++) {
			if (i != j) {
				if (x + A > 2000000 || y - B <1)
					continue;
				if ((x <= point[j].row) && (point[j].row < x + A) && (point[j].col <= y) && (point[j].col > y - B)) {
					if (point[j].weight > max_num)
						max_num = point[j].weight;
					if (point[j].weight < min_num)
						min_num = point[j].weight;
				}
			}
		}

		if (max_num - min_num > answer)
			answer = max_num - min_num;
	}

	return answer;
}

int main(void) {
	int N, A, B;
	cin >> N >> A >> B;

	vector<node> point(N);

	for (int i = 0; i < N; i++) {
		cin >> point[i].row >> point[i].col >> point[i].weight;
	}

	sort(point.begin(), point.end(), comp);

	cout << max_weight(point, N, A, B);
}
