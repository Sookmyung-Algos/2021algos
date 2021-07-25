// 16916 부분 문자열 골드4
// kmp 알고리즘 & 문자열

#include <iostream>
#include <vector>

using namespace std;

vector<int> make_table(string &p, int plen)
{
	// 문자열 테이블을 만드는 함수
	vector<int> table(plen, 0);
	// 문자열 P의 길이만큼의 크기의 벡터를 0으로 초기화
	// 테이블 선언
	int j = 0;
	for (int i = 1; i < plen; ++i) {
		if (j > 0 && p[i] != p[j]) {
			// j > 0 : 이미 최소 한 번 이상은 비교를 했다
			j = table[j - 1];
		}
		if (p[i] == p[j]) {
			// 만약 문자가 같다면 테이블의 해당 위치에 같은 문자의 개수를 저장함
			table[i] = ++j;
		}
	}
	return table;
}

int kmp(string &s, string &p)
{
	int slen = (int)s.size();
	int plen = (int)p.size();
	int j = 0;
	vector<int>t = make_table(p, plen);
	
	for (int i = 0; i < slen; ++i) {
		if (j > 0 && s[i] != p[j]) {
			j = t[j - 1];
		}
		if (s[i] == p[j]) {
			if (j == plen - 1) {
				// 문자열 s의 i번째 문자와 문자열 p의 j번째 문자가 같고,
				// j의 크기가 문자열 p의 길이에 1을 뺀 값과 같으면
				// 문자열 p가 문자열s에 속한다는 뜻이므로 1을 리턴함
				return 1;
			}
			else j++;
		}
	}
	// 포함되지 않는 경우에는 0을 리턴함
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string S, P;
	cin >> S;
	cin >> P;

	cout << kmp(S, P) << "\n";
	return 0;
}
