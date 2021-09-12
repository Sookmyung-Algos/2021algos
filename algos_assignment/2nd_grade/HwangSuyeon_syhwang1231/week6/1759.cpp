// 1759: 암호 만들기 (Gold 5)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int l, c;
vector<char> arr;

void sol(string str, int pos, int vowel, int cons){  // pos는 알파벳 배열에서 탐색 시작할 인덱스
    if(str.size() == l){
        if(vowel<1 || cons<2)
            return;
        cout << str << "\n";
    }
    
    for(int i=pos;i<c;i++){
        if(arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u'){  // 모음인 경우
            sol(str+arr[i], i+1, vowel+1, cons);
        }
        else
            sol(str+arr[i], i+1, vowel, cons+1);
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> l >> c;
    for(int i=0;i<c;i++){
        char c;
        cin >> c;
        arr.push_back(c);
    }
    sort(arr.begin(), arr.end());
    sol("",0,0,0);
    return 0;
}
