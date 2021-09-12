#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> num;

int main(){
    int n, x;
    int count = 0;
    int back;
    
    cin >> n;
    back = n-1;
    
    for(int i =0; i<n;i++){
        int a;
        cin >>a;
        num.push_back(a);
    }
    cin >>x;
    
    sort(num.begin(), num.end());
    
    for(int i=0; i<n;i++){
        for(int j = back; j>i; j--){
            if(num[i]+num[j] == x){
                count++;
                back = j;
            }
            else if(num[i]+num[j] < x){
                break;
            }
        }
    }
    cout << count;
    
}
