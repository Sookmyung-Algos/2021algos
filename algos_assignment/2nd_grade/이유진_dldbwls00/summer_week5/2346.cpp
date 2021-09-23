#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<pair<int, int>> v;
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		v.push_back(make_pair(temp, i + 1)); //(값, 인덱스+1)로 초기화
	}

    int now = 0, next;
    while (!v.empty()) {
        cout << v[now].second;
        next = v[now].first;
        if (next > 0)   next -= 1;

        v.erase(v.begin() + now);
        now += next;
        n--;

        if (n <= 0) break;
        now = (now >= 0 ? now : n + now % n); //음수 모듈러 계산
        now %= n;
        cout << " ";
    }
    return 0;
}
