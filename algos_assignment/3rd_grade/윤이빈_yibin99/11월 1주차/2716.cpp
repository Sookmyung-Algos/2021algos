#include <iostream>
#include <string>
using namespace std;
int n;
int maxVal=1;

void cnt(string s, int idx, int sum){
    if(s[idx]=='['){
        cnt(s, idx+1, sum*2);
    }
    else if(s[idx]==']'){
        if(sum>maxVal) maxVal=sum;
        cnt(s, idx+1, sum/2);
    }
    else return;
}

int main(){
	string t;
	cin >> n;
	getline(cin, t);
    for(int i=0;i<n;i++){
        string s;
    	getline(cin, s);
        maxVal=1;
        cnt(s, 0, 1);
        cout << maxVal << "\n";
    }
}
