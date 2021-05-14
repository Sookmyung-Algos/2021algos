#include<iostream>
#include<algorithm>
#include<vector>
//자료형의 사이즈를 알 수 있게 해주는 헤더
#include<climits>

using namespace std;

vector<long long> num;

int main(){
    int n, back;
    long long sum, min_sum = LLONG_MAX;
    
    cin >>n;
    back = n-1;
    
    for(int i =0; i<n;i++){
        long long a;
        cin >>a;
        num.push_back(a);
    }
    
    sort(num.begin(), num.end());
    
    for(int i =0; i<n;i++){
        for(int j = back; j > i; j--){
            sum = num[i] + num[j];
            if(llabs(sum) < llabs(min_sum)){
                min_sum = sum;
            }
            if(sum < 0){
                break;
            }else{
                back--;
            }
        }
    }
    cout << min_sum;
}
