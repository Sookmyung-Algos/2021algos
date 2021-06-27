#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>

using namespace std;

vector<int> num;

int n, m;

int check(int mid){
    
    vector<int>v;
    
    int m_cnt = 1;
    
    for(int i = 0; i < n; i++){
        v.push_back(num[i]);
        
        sort(v.begin(), v.end());
        
        int gap = v[v.size()-1] - v[0];
        
        if(gap > mid){
            m_cnt++;
            v.clear();
            v.push_back(num[i]);
        }
        
    }
    
    if(m_cnt <= m){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    
    cin >> n >> m;
    int max = 0, left = 0;
    
    for(int i =0; i<n; i++){
        int a;
        
        cin >> a;
        
        if(max < a){
            max = a;
        }
        
        num.push_back(a);
    }
    
    int answer = max;
    
    while(left <= max){
        int mid = (left + max) / 2;
        
        if(check(mid)){
            if(answer > mid){
                answer = mid;
            }
            max = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    
    cout << answer;
    
}
