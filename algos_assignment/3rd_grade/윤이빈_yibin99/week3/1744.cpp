#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, nums[10001];
    int total=0, temp=0, i;
    cin >> n;
    for(i=0;i<n;i++)
        cin >> nums[i];
    sort(nums, nums+n);
    for(i=0;i<n;i++){
        if(nums[i]<0){
            if(temp!=0){
                temp*=nums[i];
                total+=temp;
                temp=0;
            }
            else temp=nums[i];
        }
        else if(nums[i]==0) temp=0;
        else if(nums[i]==1) total+=nums[i];
        else break;
    }
    total+=temp; temp=0;
    for(int j=n-1;j>=i;j--){
        if(temp!=0){
            temp*=nums[j];
            total+=temp;
            temp=0;
        }
        else temp=nums[j];
    }
    total+=temp;
    cout << total;
}
