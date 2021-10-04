#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int n){
    for(int i=2;i<=64;i++){
        int num = n;

        string str;
        while(num){
            str.push_back(num%i);
            num /= i;
        }

        string reverse_str;
        for(int j=str.length() -1 ;j>=0;j--){
            reverse_str += str[j];
        }

        if(reverse_str == str) return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    for(int i=0;i<t;i++){
        int n;
        cin >> n;
        cout << isPalindrome(n)<<"\n";
    }
    return 0;
}