#include <iostream>
using namespace std;

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	int cnt = 0;
	for (int i = 0; i < N; i++){
		string str;
		cin >> str;
		cnt++;
		int arr[26] = { false, };  //입력여부 체크
		for (int j = 0; j < str.length(); j++){
			char ch = str[j] - 'a';
			if (arr[ch] == false){
				arr[ch] = true;
			}
			else{
				if (str[j] != str[j - 1]){
					cnt--;
					break;
				}
			}

		}
	}
	cout << cnt;
	return 0;
}
