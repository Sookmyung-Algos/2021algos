//5904 Moo 게임

#include <iostream>

using namespace std;

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	int currLength = 3; // 현재 수열의 길이, 0번째 수열 = "moo"
	int middLength = 3;  // k번째 수열에서 k-1번째 수열 길이를 뺀 "m o ...o" 문자열(=중간수열)의 길이

	while (n > currLength)  // n이 현재 수열의 길이보다 크다면
	{
		currLength = currLength * 2 + ++middLength;    // 규칙에 따라 수열 늘리기
	}

    while (1) {
        int d  = (currLength - middLength) / 2;  // d는 직전 수열의 길이


        if (n <= d) { // 중간수열보다 앞에 있음
            middLength--;
            currLength = d; 
            // 현재 수열 자체가 이전 수열로 재정의되므로 중간수열도 1만큼 짧아짐
        }

        else if (n > d + middLength) {   // 중간수열보다 뒤에 있음
            n -= d + middLength;
            middLength--;
            currLength = d;
        }   // 현재 수열에서 d + middLength만큼의 문자열을 없애는 것이므로 n에서도 같은 값을 줄임

        else {  // 중간수열 중에 있음
            n -= d;
            break;
        }   // 중간수열에 해당하므로 이전 수열만큼을 빼면 답을 구할 수 있음
    }

    if (n == 1)
        cout << "m";
    else
        cout << "o";

    return 0;
}
