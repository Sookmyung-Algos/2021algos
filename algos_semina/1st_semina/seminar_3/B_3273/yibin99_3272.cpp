#include <iostream>
#include <algorithm>
using namespace std;

int arr[100000];

int main(){
    int n, x, cnt=0;
    int s, e;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> arr[i];
    cin >> x;
    sort(arr, arr+n);
    s=0, e=n-1;
    while(s<e){
        int sum=arr[s]+arr[e];
        if(sum>x) e--;
        else if(sum<x) s++;
        else{
            cnt++;
            e--;
        }
    }
    cout << cnt;
}
