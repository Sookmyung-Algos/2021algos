//baekjoon 20044 project teams

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int n;	//팀 수
	vector<int> stu;
	int tmp, res = 200001;	//결과를 저장하게 될 변수 ans, 나올 수 있는 역량 합의 최댓값이 200,000이므로 200,001로 초기화

	cin >> n;

	for (int i = 0; i < 2 * n; i++) {
		cin >> tmp;
		stu.push_back(tmp);
	}

	sort(stu.begin(), stu.end());	//학생들의 역량 값을 오름차순 정렬

	for (int i = 0; i < 2 * n; i++) {	//제일 왼쪽, 오른쪽에서 한 칸씩 이동하며 합을 비교
		res = min(res, stu[i] + stu[2 * n - 1 - i]);
	}

	cout << res;
	return 0;
}
