#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(string a, string b)
{
	if (a.length() == b.length())	//길이가 같으면
		return a < b;	//단어가 모두 소문자이므로 사전적인 순서만 비교
	else
		return a.length() < b.length();
}

int main(void)
{
	vector<string> v;
	int n;	//입력할 단어의 개수
	string str, temp;
	cin >> n;

	for (int i = 0; i < n; i++)		//n번동안 입력받기
	{
		cin >> str;
		v.push_back(str);	//벡터 v에 입력받은 문자열을 push
	}
	sort(v.begin(), v.end(),compare);		//vector의 원소를 compare 함수를 사용해 정렬

	for (int i = 0; i < n; i++)		//중복되는 단어 확인 후 출력
	{
		if (temp == v[i])	//이전 단어와 중복되는지 확인
			continue;	//중복되면 다음 루프
		else	//중복되지 않으면 
		{
			cout << v[i] << "\n";
			temp = v[i];
		}
	}
	return 0;
}
