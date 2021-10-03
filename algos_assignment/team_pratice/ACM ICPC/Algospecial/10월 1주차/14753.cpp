#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

vector<int> plus_v;
vector<int> minus_v;

int main(){
    int n;

    cin >> n;

    for(int i = 0; i < n; i++){
        int a;

        cin >> a;

        if(a >= 0){
            plus_v.push_back(a);
        }
        else{
            minus_v.push_back((a * -1));
        }
    }

    sort(plus_v.begin(), plus_v.end());
    sort(minus_v.begin(), minus_v.end());

    int minus_max2 = 0;
    int plus_max2 = 0;
    int minus_max3 = 0;
    int plus_max3 = 0;

    if(minus_v.size() >= 2){
        minus_max2 = minus_v[minus_v.size() - 1] * minus_v[minus_v.size() - 2];
        minus_max3 = minus_v[minus_v.size() - 1] * minus_v[minus_v.size() - 2];
        if(plus_v.size()>=1){
            minus_max3 *= plus_v[plus_v.size()-1]; 
        }
    }

    if (plus_v.size() >= 2){
        plus_max2 = plus_v[plus_v.size() - 1] * plus_v[plus_v.size() - 2];
        if(plus_v.size() >= 3){
            plus_max3 = plus_max2 * plus_v[plus_v.size() - 3];
        }
    }

    int answer = 0;

    answer = max(minus_max2, minus_max3);
    answer = max(answer, plus_max2);
    answer = max(answer, plus_max3);

    cout << answer;

}
