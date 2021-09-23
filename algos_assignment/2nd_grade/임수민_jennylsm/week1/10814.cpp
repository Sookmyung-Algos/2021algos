#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	int A;
	cin >> A;
	vector<string> p(A);  //나이, 가입순서를 저장할 벡터
	vector<pair<int, int>> v(A);  //이름을 저장할 벡터
	for (int i = 0; i < A; i++) {
		cin >> v[i].first >> p[i];  //값을 입력받는다
		v[i].second = i;
	}
	sort(v.begin(), v.end());  //입력받은 값을 sort를 이용하여 정렬한다
	for (int i = 0; i < A; i++)
		cout << v[i].first << " " << p[v[i].second] << '\n';  //정렬한 값을 출력한다
	return 0;
}
