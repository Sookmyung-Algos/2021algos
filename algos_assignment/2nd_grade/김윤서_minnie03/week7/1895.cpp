#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int r, c, t;
	int pixel[45][45];

	cin >> r >> c;
	for (int i = 0; i < r; i++) { //i행j열 pixel 입력
		for (int j = 0; j < c; j++) {
			cin>>pixel[i][j];
		}
	}

	cin >> t;
	int result = 0; //결과 0으로 초기화

	for (int i = 0; i < r - 2; i++) { 
		for (int j = 0; j < c - 2; j++) {
			vector<int> filter; //현재 범위내의 9개 숫자를 저장할 벡터 필터
			for (int a = 0; a <=2; a++) { //3행
				for (int b = 0; b <= 2; b++) { //3열
					filter.push_back(pixel[i + a][j + b]); //9개의 값을 차례대로 filter에 저장
				}
			}
			sort(filter.begin(), filter.end()); //filter의 원소들을 정렬
			if (filter[4] >= t) result++; //만약 중간값이 t보다 크거나 같다면 result 1증가, 작다면 그대로 유지
		}
	}
	
	cout << result << endl; //최종 result값 출력
	return 0;
}
