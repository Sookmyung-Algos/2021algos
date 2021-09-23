#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string fr, string se) //길이판단 함수
{
	int i = 0;
	if (fr.length() == se.length())
	{
		for (int i = 0; i < fr.length(); i++)
		{
			if (fr[i] != se[i])
				return fr[i] < se[i];
		}
	}
	return fr.length() < se.length();
}

int main()
{
	int n;
	string voca; 
	vector<string> arr;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> voca;
		arr.push_back(voca);
	}
	sort(arr.begin(), arr.end(), cmp);
	
	cout << arr[0] << endl;   //출력하기
	for (int i = 1; i < n; i++)
	{
		if (arr[i - 1] == arr[i])
			continue;
		cout << arr[i] << endl;
	}
	
	return 0;
}
