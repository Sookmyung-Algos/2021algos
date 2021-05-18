#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, w, ans = 200001; //ans의 초기값 200001로 설정(코딩 역량의 합은 최대 200000)
	vector<int> cod;
	cin >> n;
	for (int i = 0; i < 2 * n; i++) {
		cin >> w;
		cod.push_back(w); //학생들의 코딩 역량을 입력받아 벡터 cod에 저장
	}
	sort(cod.begin(), cod.end()); //코딩 역량을 오름차순으로 정렬

	for (int i = 0; i < 2 * n; i++) {
		ans = min(ans, cod[i] + cod[2 * n - 1 - i]); //같은 팀에 속한 두 학생의 코딩 역량을 더한 값과 새로운 팀의 코딩 역량 합의 값을 비교하며 최솟값을 업데이트 함
	}
	cout << ans;
}
