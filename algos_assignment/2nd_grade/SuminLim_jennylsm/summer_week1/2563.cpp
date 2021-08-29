#include<iostream>
using namespace std;

int main(void){
	int p, result = 0;
	int x, y;
	cin >> p;
	bool map[100][100] = { 0 };   //전체 칸 초기화
	for (int i = 0; i < p; i++){
		cin >> x >> y;
		for (int j = 99 - y; j > (99 - y) - 10; j--){
			for (int k = x; k < x + 10; k++){
				map[j][k] = true;  //색종이가 되는 부분 true로 바꿔줌
			}
		}
	}
	for (int i = 0; i < 100; i++){
		for (int j = 0; j < 100; j++){
			if (map[i][j] == true)
				result++;  //true 만 더해서 결론도출
		}
	}
	cout << result;
	return 0;
}
