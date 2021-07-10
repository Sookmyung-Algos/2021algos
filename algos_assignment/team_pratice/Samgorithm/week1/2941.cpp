#include <iostream>
using namespace std;
string str;

int main() {
    cin >> str;
    int cnt=0;
    for (int i=0;i<str.length();i++){
        char c = str[i];
        if (c=='l' || c=='n'){
            if (str[i+1]=='j'){
                continue;
            }
        } else if (c=='c' || c=='s' || c=='z'){
            if (str[i+1]=='=' || str[i+1]=='-'){
                continue;
            }
        } else if (c=='d'){
            if ((str[i+1]=='z'&& str[i+2]=='=') || str[i+1]=='-'){
                continue;
            }
        } else if (c=='NULL') break;
        cnt++;
    }
    cout << cnt;
    return 0;
}
