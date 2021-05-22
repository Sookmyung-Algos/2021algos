#include <iostream>
#include <cstring>
using namespace std;

int calculate(char c){
    int a = (int)c;
    a = a / 100 + a / 10 - a / 100 * 10 + a % 10;
    return a;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    for(auto c : s){
      int num = calculate(c);
      while(num--){
        cout << c;
      }
      cout << "\n";
    }
}

