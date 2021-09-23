#include <iostream>
#include <list>
using namespace std;

int main() {
    // 시간 초과
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, k; // 변수 선언
    list<int> lis; // list 선언

    cin >> n >> k; // 입력

    //1~n번까지 숫자넣기
    for (int i = 1; i <= n; i++) {
        lis.push_back(i);
    }

    //k번째 사람 출력하고 삭제하기

    list<int>::iterator kill = lis.begin();
	for (int i = 0; i < k - 1; i++) // kill = k
		kill++;

	cout << '<';

	while (n > 0) {
		if (n == 1) { // 마지막 하나 남으면 while문 나오기
			cout << *kill;
			break;
		}

		cout << *kill << ", ";

		kill = lis.erase(kill);
		if (kill == lis.end()) // 원형 큐
			kill = lis.begin(); 
		--n;

		for (int i = 0; i < k - 1; i++) {
			kill++;
			if (kill == lis.end()) 
				kill = lis.begin();
		}
	}
	cout << '>';
}
