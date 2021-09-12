#include <iostream>
using namespace std;

int main(){
    int t;
    string ps;
    cin >> t;
    while(t>0){
        cin >> ps;
        int cnt=0;
        string ans="YES";
        for(int i=0;i<ps.length();i++){
            if(ps[i]=='(')
                cnt++;
            else{
                if(cnt>0)
                    cnt--;
                else{
                    ans="NO";
                    break;
                }
            }
        }
        if(cnt>0) ans="NO";
        cout << ans << "\n";
        t--;
    }
}
