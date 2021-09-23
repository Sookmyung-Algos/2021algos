#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	int pack[51],one[51]; //패키지 가격과 낱개의 가격
	int min = 1000; //기타줄 하나 가격의 최솟값 (1000으로 초기화)
	int setmin = 6000; //6개 묶음 가격의 최솟값 (6000으로 초기화)

	cin >> n >> m; 
	int six = n / 6; //끊어진 기타줄이 6의 몇배 이상인지 저장
	int remainder = n % 6; //끊어진 기타줄 개수를 6으로 나눈 나머지 저장
	int result;

	if (six == 0) { //끊어진 기타줄 개수가 6보다 작을 때
		for (int i = 0; i < m; i++) {
			cin >> pack[i] >> one[i];
			if (pack[i] > (one[i] * n)) { //낱개로만 했을 때 더 싼 경우
				min = (min < (one[i] * n)) ? min : (one[i] * n); //min과 낱개로만 했을때의 가격 중 더 작은 값을 min에 저장
			}
			else { //패키지 가격이 더 싸다면
				min = (min < pack[i]) ? min : pack[i]; //min과 패키지 가격 중 더 작은 값을 min에 저장
			}
		}
		result = min;
	}
	else { //끊어진 기타줄 개수가 6 이상일 때
		for (int i = 0; i < m; i++) {
			cin >> pack[i] >> one[i];

			if (pack[i] > one[i] * 6) { //낱개 가격으로 6개 묶은 것이 패키지보다 싼 경우
				setmin = (setmin<one[i] * 6)?setmin:one[i]*6; //setmin과 낱개 6개 묶음 가격 중 더 싼 것을 setmin에 저장
			}
			else { //패키지 가격이 더 싸다면
				setmin = (setmin < pack[i]) ? setmin : pack[i]; //setmin과 패키지 가격 중 더 싼 것을 setmin에 저장
			}
			
			if (pack[i] > one[i] * remainder) { //나머지 낱개만 따로 사는 것이 패키지보다 싼 경우
				min = (min < one[i] * remainder) ? min : one[i] * remainder; //min과 낱개의 합 중 더 싼 것을 min에 저장
			}
			else { //패키지가 오히려 나머지 낱개 사는 것보다 더 싼 경우
				min = (min < pack[i]) ? min : pack[i]; //min과 패키지 중 더 싼 것을 min에 저장
			}
		}
		result = setmin*six+min;
	}

	cout << result << endl; //필요한 돈의 최솟값 출력
	return 0;
}
