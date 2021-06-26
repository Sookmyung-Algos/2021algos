#include <iostream>
#include <cstring>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string temp;
    getline(cin,temp);
    
    int i=0,cnt=0;
    string str = "UCPC\n";
    while (i<temp.size()){
        if (temp[i] == str[cnt]) cnt++;
        else if (cnt==4) break;
        i++;
    }
    if (cnt==4) cout << "I love UCPC" << '\n';
    else cout << "I hate UCPC" << '\n';
    return 0;
}
