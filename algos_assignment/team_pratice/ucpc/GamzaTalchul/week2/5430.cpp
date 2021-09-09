#include<iostream>
#include<string>
#include<deque>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T, p;
	bool FR, err;
	string str, numline;

	cin >> T;

	while (T--) {
		deque<int> dq;
		FR = true;
		err = false;
		cin >> str >> p >> numline;
		int i = 1;
		while (numline[i] != '\0') {
			int x = 0;
			while (numline[i] >= '0' && numline[i] <= '9') {
				x *= 10;
				x += int(numline[i] - '0');
				i++;
			}
			if (x != 0) {
				dq.push_back(x);
			}
			i++;
		}

		i = 0;
		while (str[i] != '\0') { //여기서 문자열 판별
			if (str[i] == 'R') {
				FR = !FR;
			}
			else if (str[i] == 'D') {
				if (dq.empty()) { //deque가 비어있을때 D명령어가 나오면 error
					cout << "error" << endl;
					err = true;
					break;
				}
				if (FR) {
					dq.pop_front();
				}
				else {
					dq.pop_back();
				}
			}
			i++;
		}

		//출력하는 부분 error 여부에 따라 '[',']'기호도 출력할지 판단
		if (!err) {
			cout << "[";
		}
		while (!dq.empty()) {
			if (FR) {
				auto c = dq.front();
				dq.pop_front();
				cout << c;
			}
			else {
				auto c = dq.back();
				dq.pop_back();
				cout << c;
			}
			if (!dq.empty()) {
				cout << ",";
			}
		}
		if (!err) {
			cout << "]" << endl;
		}
	}
}
