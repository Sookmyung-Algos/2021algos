#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
int n;
vector<int> v;
 
int main() {
    // 시간 초과
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
 
    cin >> n; // 수열의 크기
    v.push_back(0);
  
    int num;
    for (int i = 0; i < n; i++) {
        cin >> num; // 수열을 이루는 수 입력
        
        if (num > v.back()) { // 벡터의 마지막 값보다 크면(증가)
            v.push_back(num); // push하기
        }
        else { // 작거나 같다면
            //num이상의 값이 처음으로 나타나는 위치에 num을 넣기
            int index = lower_bound(v.begin(), v.end(), num) - v.begin();
            v[index] = num;
        }
    }
  
    //처음에 넣어놓은 0을 제외한 벡터의 사이즈가 최장 증가 수열의 길이
    cout << v.size() - 1 << '\n';
 
    return 0;
}
