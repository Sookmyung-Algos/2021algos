#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <string> 

using namespace std;
int main() { 
	ios::sync_with_stdio(false); 
	cin.tie(0); cout.tie(0); //입출력 속도개선
	string str; 
	cin >> str; 
	sort(str.begin(), str.end(),greater<>());
	if (str[str.length() - 1] != '0') 
		cout << -1; //0없으면 -1출력
	else { 
		long long sum = 0; 
		for (auto o : str) { //반복자 사용
			sum += o-'0'; 
		} 
	if (sum % 3 == 0) 
		cout << str; 
	else 
		cout << -1;
	} 
}
