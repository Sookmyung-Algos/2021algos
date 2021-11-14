#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

string num[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

map <string, int> answer;

int main(){
    
    int n, m;
    
    cin >> m >> n;
    
    for(int i = m; i <= n; i++){
        string s;
        
        if(i >= 10){
            s = num[i / 10] + num[i % 10];
        }
        else{
            s = num[i];
        }
        
        answer[s] = i;
    }
    
    int cnt = 0;
    
    for(auto s : answer){
        cout << s.second << " ";
        cnt++;
        
        if(cnt % 10 == 0){
            cout << "\n";
        }
    }
    
}
