#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, w, ans = 200001;
	vector<int> v; //int형 vector v 선언

	cin >> n;
	for (int i = 0; i < 2 * n; i++) { //2n개의 코딩 역량을 입력받아 vector v에 저장
		cin >> w;
		v.push_back(w);
	}
	sort(v.begin(), v.end()); //코딩 역량을 오름차순 정렬

	for (int i = 0; i < 2 * n; i++) //2n개의 코딩 역량을
		ans = min(ans, v[i] + v[2 * n - 1 - i]); //가장 작은 값과 가장 큰 값을 순서대로 합해 가장 작은 역량의 합을 ans에 저장
	cout << ans; //ans 값 출력
}
