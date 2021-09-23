#include <iostream>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;
int T;
bool iserror = false;
deque<int> dq;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	while (T--) {
		int num;
		string p, arr, element;

		cin >> p >> num >> arr;
		// 배열 원소 디큐에 저장하기
		for (int i = 0; i < arr.length(); i++) {
			if (num == 0) break;
			if (arr[i] == '[') continue;
			else if ('0' <= arr[i] && arr[i] <= '9') element += arr[i];
			else if (arr[i] == ',' || arr[i] == ']') {
				dq.push_back(stoi(element));
				element.clear();
			}
		}
		// 명령문 수행
		int r = 0;
		for (int i = 0; i < p.length(); i++) {
			if (p[i] == 'R') r++; //모든 경우에 reverse()를 수행하면 시간 초과가 발생하므로 카운트를 해주고
			else if (p[i] == 'D') {
				if (dq.empty()) {
					iserror = true;
					break;
				}
				else if (!dq.empty() && r % 2 != 0) dq.pop_back(); // R호출 횟수가 홀수이면 pop_back()을 해주고
				else dq.pop_front();	// 짝수이면 pop_front()를 해준다.
			}
		}

		if (iserror == true) cout << "error\n";
		else {
			cout << "[";
			if (r % 2 != 0) reverse(dq.begin(), dq.end()); // 최종적인 R호출 횟수가 홀수이면 reverse()함수를 실행한다.
			for (int j = 0; j < dq.size(); j++) {
				cout << dq[j];
				if (j < dq.size() - 1) cout << ",";
			}
			cout << "]\n";
		}
		iserror = false;
		dq.clear();
	}
	
	return 0;
}
