#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,x;
vector<int> nums;
int cnt = 0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> n;
    int tmp;
    for(int i = 0 ; i < n ; i++){
        cin >> tmp;
        nums.push_back(tmp);
    }
    cin >> x;
    sort(nums.begin(),nums.end());
    int start = 0;
    int end = n - 1;
    while(1){
        if(start >= end) break;
        tmp = nums[start] + nums[end];
        if(tmp == x){
            start++;
            end--;
            cnt++;
        }
        else if(tmp > x) end--;
        else start++;
    }

    cout << cnt;
}
