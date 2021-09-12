#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;
    int ans=0, cnt=0;
    for(int i=0;i<s.length()-1;i++){
        if(s[i]=='('){
            if(s[i+1]=='(')
                cnt++;
            else
                ans+=cnt;
        }
        else if(s[i+1]==')'){
                ans++;
                cnt--;
        }
    }
    cout << ans;
}
