#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> arr;

int count(int mid){
    int min_val, max_val, cnt=1;
    min_val=arr[0];
    max_val=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]<min_val) min_val=arr[i];
        if(arr[i]>max_val) max_val=arr[i];
        if(max_val-min_val>mid){
            cnt+=1;
            min_val=arr[i];
            max_val=arr[i];
        }
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int max_num=0;
    cin >> n >> m;
    arr.resize(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
        if(arr[i]>max_num) max_num=arr[i];
    }
    int left=0, right=max_num, mid;
    int res=max_num;
    while(left<=right){
        mid=(left+right)/2;
        int cnt = count(mid);
        if(cnt>m){
            left=mid+1;
        }
        else{
            right=mid-1;
            if(mid<res) res=mid;
        }
    }
    cout << res;
}
