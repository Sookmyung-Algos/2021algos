// 2304: 창고 다각형 (Silver 2)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int N;
    vector<pair<int, int>> height;
    cin >> N;
    for(int i=0;i<N;i++){
        int l,h;
        cin >> l >> h;
        height.push_back({l,h});
    }
    sort(height.begin(), height.end());
    
    // 제일 큰 기둥 기준으로 왼쪽 넓이
    int leftIdx = height[0].first;
    int leftMaxH = height[0].second;
    int total = 0;
    
    for(auto p:height){
        if(p.second>=leftMaxH){
            total += (p.first-leftIdx)*leftMaxH;
            leftMaxH = p.second;
            leftIdx = p.first;
        }
    }
    // 제일 큰 기둥 기준으로 오른쪽 넓이
    int rightIdx = height.back().first;
    int rightMaxH = height.back().second;
    for(int i=height.size()-1;i>=0;i--){
        auto p = height[i];
        if(p.second>rightMaxH){
            total+=(rightIdx-p.first)*rightMaxH;
            rightMaxH = p.second;
            rightIdx = p.first;
        }
    }
    
    cout << total + leftMaxH;
    return 0;
}
