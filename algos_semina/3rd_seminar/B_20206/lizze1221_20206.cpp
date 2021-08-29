#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	int tmp = 0; // 점과 직선의 위치를 표시하기 위한 매개변수
	int rec[4];
	cin >> a >> b >> c;
	for (int i = 0; i < 4; i++) {
		cin >> rec[i];
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 2; j <= 3; j++) {
			int num = a*rec[i] + b*rec[j] + c;

			if (num == 0) {
				cout << "Lucky"<<"\n";
				return 0;
			}
			if (num > 0 && tmp == 0) tmp = 1;
			else if (num < 0 && tmp == 0) tmp = -1;
			
			if (num*tmp < 0) { 
				cout << "Poor" << "\n";
				return 0;
			}

		}
	}
	cout << "Lucky" << "\n";

	return 0;
}
