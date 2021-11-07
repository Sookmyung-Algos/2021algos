#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>

#define MAX 1010

using namespace std;

int n, m;
vector<long long> card;

int main(){
    
    cin.tie(0);
    cin.sync_with_stdio(false);
    
    cin >> n;
    
    for(int i = 0; i< n; i++){
        long long num;
        
        cin >> num;
        
        card.push_back(num);
    }
    
    sort(card.begin(), card.end());
    
    int cnt = 1, max_cnt = 0;
    long long num = 0;
    
    for(int i = 0; i < card.size() - 1; i++){
        if(card[i] == card[i+1]){
            cnt++;
            
            if(cnt > max_cnt){
                max_cnt = cnt;
                num = i;
            }
        }
        else{
            cnt = 1;
        }
    }
    
    cout << card[num];
    
}

