#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, sum;
    sum = 0;
    cin >> n;
    stack<int> s;
    while(n--){
        int num;
        cin >> num;
        if(num == 0){
            if(!s.empty()) s.pop();
        }
        else s.push(num);

    }
    
    while(!s.empty()){
        sum += s.top();
        s.pop();
    }
    cout << sum;
    
}
