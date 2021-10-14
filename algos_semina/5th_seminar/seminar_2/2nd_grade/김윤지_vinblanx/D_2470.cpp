#include <iostream>
#include <algorithm>
#include <math.h>
#include <climits>
#define MAX 100001

using namespace std;

int n;
long long arr[MAX];
long long mini = LLONG_MAX;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int start = 0;
    int end = n - 1;
    int ix_1, ix_2;
    while(start < end){
        long long sum=arr[start]+arr[end];
        if(llabs(sum)<mini){
            mini = llabs(sum);
            ix_1 = start;
            ix_2 = end;
        }
        if(sum < 0){
            start++;
        }
        else{
            end--;
        }
    }
    cout << arr[ix_1] << " " << arr[ix_2] << "\n";
    return 0;
}
