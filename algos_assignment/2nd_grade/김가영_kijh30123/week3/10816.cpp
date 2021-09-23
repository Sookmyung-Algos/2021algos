#include <iostream>
#include <vector>
#include <algorithm> //sort, upper_bound, lower_cound사용

using namespace std;

int main()
{
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false); //입출력 속도 개선
	vector <int>v;
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++) { //카드를 받고 벡터로 저장
		int card;
		cin >> card;
		v.push_back(card);
	}
	sort(v.begin(), v.end()); //정렬

	cin >> m;
	for (int i = 0; i < m; i++) { //찾아야 하는 카드를 받고
		int key;
		cin >> key;
		cout << upper_bound(v.begin(), v.end(), key) - lower_bound(v.begin(), v.end(), key) << " ";
	} //찾고자 하는 값보다 큰 값이 처음 나타나는 위치-찾고자하는 값 이상이 처음 나타나는 위치=카드의 개수
}
