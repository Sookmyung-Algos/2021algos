#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    int num[20001];
    cin>>n;
    for (int i = 0; i< n; i++) 
        cin >> num[i];
    sort(num,num+n);
    cout << num[(n-1)/2];
    // 정렬 후 가운데 숫자 출력= n이 홀수일 때 중앙값, n이 짝수일 때 중앙값 2개 중 작은 값 출력
}
