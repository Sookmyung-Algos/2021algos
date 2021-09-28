#include <iostream> 
#include <vector> 
using namespace std; 

int main(void) { 
	ios_base::sync_with_stdio(0); cin.tie(0); 
	
	int n; 
	vector<pair<int, int>> v; 

	cin >> n; // 터진 풍선의 번호 입력 
	
	for (int i = 0; i < n; i++) { 
		int num; 
		cin >> num; 
		v.push_back({ i + 1, num }); // vector에 순서와 적혀있는 수 
	} 
	
	int idx = 0; 
	int copyN = n; 
	
	for (int i = 0; i < copyN; i++) {
		cout << v[idx].first << " "; 

		int move = v[idx].second; // 이동할 만큼
	
		// 풍선을 터뜨리고 움직인다
		if (move > 0) 
			move--; 
		v.erase(v.begin() + idx); 
		idx += move; 

		if (--n== 0) 
			break;

		// 인덱스가 음수라면 모듈러 연산을 이용해야함
		idx = (idx >= 0 ? idx : n + idx % n); 
		idx %= n; 
	} 

	cout << "\n"; return 0; 
}
