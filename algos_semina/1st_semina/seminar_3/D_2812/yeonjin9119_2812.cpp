#include <iostream>
#include <list>
using namespace std;
int n, k;
list<int> str;
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		char c; // 한 글자씩 비교하기 위해 int가 아닌 char형으로 받음
		cin >> c;
		str.push_back(c - '0');
	}
	int d = 0;// 큰 값을 몇개 찾았는지 기재하기 위함
	list <int>::iterator iter;
	for (iter = str.begin(); iter != str.end();) {// 앞뒤의 수를 비교하며 가장 큰 값들을 찾음
		list <int>::iterator next = iter;
		next++;
		if (next == str.end())//입력받은 것 1개
			break;
		if (*iter >= *next) {// 현재 수 > 다음 수
			iter++;
			continue;
		}
		else if (*iter < *next) {// 현재 수< 다음 수 => 작은 현재수를 삭제함.
			iter = str.erase(iter);
			if (iter != str.begin())
				--iter;
			if (++d == k)
				break;
		}
	}
	if (d != k) {// 삭제되야 할 만큼 삭제가 안되었을 경우 = 앞에 가장 큰 수가 만들어지고 뒤는 모두 작은수
		//=> 뒤의 값을 삭제해주면 가장 큰값만 남음
		for (int i = d; i < k; ++i) {
			str.erase(--str.end());
		}
	}
	for (iter = str.begin(); iter != str.end(); iter++) {
		printf("%d", *iter);
	}
	return 0;
}
