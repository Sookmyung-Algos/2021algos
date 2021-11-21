#include <iostream>
#include <algorithm>
using namespace std;

int top[101];

int main(){
    int n;
    float doughC, topC, doughCal;
    cin >> n >> doughC >> topC >> doughCal;
    for(int i=0;i<n;i++){
        cin >> top[i];
    }
    sort(top, top+n);
    int sumCal = doughCal, sumC = doughC;
    for(int i=n-1;i>=0;i--){
        if((sumCal+top[i])/(sumC+topC)>sumCal/sumC){
            sumCal+=top[i];
            sumC+=topC;
        }
    }
    cout << sumCal/sumC;
}
