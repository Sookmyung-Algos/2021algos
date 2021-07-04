#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<pair<int, int>> ice;
queue<pair<int, int>> q;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k, g, x;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> g >> x;
        ice.push_back(make_pair(x, g));
    }
    sort(ice.begin(), ice.end());
    int sum=0, max_sum=0;
    for(int i=0;i<n;i++){
        sum+=ice[i].second;
        q.push(ice[i]);
        if(!q.empty()){
            while(q.back().first-q.front().first>2*k+1){
                sum-=q.front().second;
                q.pop();
            }
        }
        if(sum>max_sum) max_sum=sum;
    }
    cout << max_sum;
}
