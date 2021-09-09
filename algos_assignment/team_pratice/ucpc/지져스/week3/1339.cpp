#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 알파벳 배열
int alpha[26];

// 비교함수
bool compare(int a, int b)
{
    if (a > b)
        return true;
    else
        return false;
}

int main() {
	int N;
	cin >> N;
	
	vector <string> v; // string 형태의 vector 

	// 문자열 입력
	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		v.push_back(input);
	}

    for (int i = 0; i < N; i++)
    {
        string s = v[i]; // 한 문장 받아오기
        int length = s.length(); // 문장 길이
        int pos = 1;

        for (int j = length - 1; j >= 0; j--)
        {
            int temp = s[j] - 'A'; // 한 글자씩 알파벳 순서대로
            alpha[temp] = alpha[temp] + pos;
            pos = pos * 10; // 뒤에 있는 것부터
        }
    }

    sort(alpha, alpha + 26, compare); // 알파벳 정렬

    int answer = 0;
    int num = 9; // 맨 앞자리 수가 9부터 배정

    for (int i = 0; i < 26; i++)
    {
        if (alpha[i] == 0) break; // 알파벳 없을때
        answer = answer + (alpha[i] * num);
        num--;
    }

    cout << answer << "\n";

	return 0;
}
