#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, cnt = 0;
	string name;
	cin >> n >> m;
	vector<string> v;
	vector<string> nhs;
	v.resize(n);    // 배열의 크기를 알기 때문에 미리 할당을 함
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < m; i++) {
		cin >> name;
		if (binary_search(v.begin(), v.end(), name)) {	
			// 입력받은 이름과 저장된 값 중에 중복된 값이 있는지 확인
			nhs.push_back(name);
			cnt++;
		}
	}

	cout << cnt << "\n";
	sort(nhs.begin(), nhs.end());
	for (int i = 0; i < cnt; i++) {
		cout << nhs[i] << "\n";
	}
	return 0;
}
