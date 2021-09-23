// 22351 수학은 체육과목입니다3(Silver 5)
#include <iostream>
#include <string>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	string s;
	cin >> s;
	
	for(int i=1;i<=3;i++){  // 가능한 숫자의 길이(1,2,3자리 수)
	    string sub = s.substr(0,i);
	    int startNum = stoi(sub);
	    int nextNum = startNum;  // string을 처음부터 만들기 위해 초기값은 startNum
	    int lastNum = startNum;
	    
	    string strMade = "";
	    for(int j=0;j<s.size();j+=to_string(nextNum).size(), nextNum++){
	        string next = s.substr(j, to_string(nextNum).size());
	    
	        if(stoi(next) != nextNum)
	            break;
	        strMade += next;
	        lastNum = nextNum;
	    }
	    
	    if(s == strMade){
	        cout << startNum << ' ' << lastNum;
	        break;
	    }
	}
	return 0;
}
