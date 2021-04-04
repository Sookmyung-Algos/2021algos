#include<iostream> //cin, cout 사용
#include<map> //map 헤더
#include<vector> //vector 헤더
#include<string> //string 쓰는데 추가 안해서 삽질했어요...
#include<algorithm> //algorithm 사용
using namespace std; //식별자가 고유하도록 보장

vector<string> v; //커스텀 정렬 함수에 쓰여서 미리 지정해줍니다
map<string, int> m; //마찬가지입니다

bool cmp(const string &a, const string &b) { //커스텀 정렬함수입니다. v를 sort했는데 key값으로 map도 참조할 수 있단걸 알았습니다.
	if (m[a] == m[b] && a.size() == b.size()) return a < b; //단어 오름차순으로
	else if (m[a] == m[b]) return a.size() > b.size(); //길이 내림차순으로
	return m[a] > m[b]; //빈도 내림차순으로
}

int main() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);//입출력개선
	int N, M;
	cin >> N >> M; //값을 입력받습니다
	for (int i = 0; i < N; i++) { //단어 갯수만큼 반복합니다
		string ap;
		cin >> ap; //단어 받습니다
		if (ap.size() < M) continue; //일정 길이가 아니라면 지나갑니다.
		if (m.find(ap) == m.end()) { //처음 저장하는 경우
				m[ap] == 0;
				v.emplace_back(ap); //이름만 따로 vector로 추가합니다
			}
		m[ap]++; //무조건 빈도수 추가	
	}
	sort(v.begin(), v.end(), cmp); //커스텀정렬 합니다
	for (string &ap : v) cout << ap << '\n'; //반복자로 출력합니다 느려서 참조형식으로 했습니다
	return 0;
}
//{}많았는데 다 없애고 조건문 줄이니까 통과되었습니다...통과 못하는줄 알았어요...
