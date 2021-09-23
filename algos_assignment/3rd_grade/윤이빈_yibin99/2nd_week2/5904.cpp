#include <iostream>
using namespace std;

int n;
char ans='o';
void check(int s, int k, int l){
    if(k==0){
        if(n==s)
            ans='m';
        return;
    }
    int mid=s+(l-k-3)/2;
    int right=mid+k+3;
    if(n<mid){
        check(s, k-1, (l-k-3)/2);
    }
    else if(n<right){
        if(n==mid)
            ans='m';
        return;
    }
    else{
        check(right, k-1, (l-k-3)/2);
    }
}

int main(){
    cin >> n;
    int k=0, len=3;
    while(n>len){
        k++;
        len=2*len+k+3;
    }
    check(1, k, len);
    cout << ans;
}
