#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> dish;
int arr[3001];

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int num, kind, con, coupon, result = 0, val;
    cin >> num >> kind >> con >> coupon;
    
    arr[coupon]=1;
    int cnt=1; 
    int l=0,r=con-1;
    
    for(int i=0;i<num;i++){
        cin >> val;
        dish.push_back(val);
        if(i<con){
            arr[val]++;
            if(arr[val]==1) cnt++;
        }
    }
    
    for(int i=0;i<con;i++)
        dish.push_back(dish[i]);
    
    while(1){
        result = max(result,cnt);
        if(l==num) break;
        arr[dish[l]]--;
        if(arr[dish[l++]]==0) cnt--;
        arr[dish[++r]]++;
        if(arr[dish[r]]==1) cnt++;
    }
    cout<<result;
    return 0;
}
