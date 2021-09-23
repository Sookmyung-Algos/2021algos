#include <iostream>
#include <cstring>
using namespace std;

char str[100000];

int find(int s, int e, int flag){
    if(s>=e) return flag;
    if(str[s]==str[e]) return find(s+1, e-1, flag);
    else{
        if(flag==1) return 2;
        else{
            int r1=find(s+1, e, flag+1);
            int r2=find(s, e-1, flag+1);
            if(r1==2 && r2==2) return 2;
            else return 1;
        }
    }
}
int main(){
    int t;
    cin >> t;
    while(t>0){
        cin >> str;
        cout << find(0, strlen(str)-1, 0) << "\n";
        t--;
    }
}
