#include <iostream>
#include<string>
#include<stack>
using namespace std;
int n;
string s;
int main() {
	cin >> n;
	int cnt=0;
	for(int i=0;i<n;i++){
		cin >> s;
		stack<char>st;
		for(int j=0;j<s.length();j++){
			if(st.empty() || s[j] != st.top()){
				st.push(s[j]);
			}
			else if(!st.empty() && s[j] == st.top()){
				st.pop();
			}
		}
		if(st.empty())cnt++;
	}
	cout << cnt;
}
