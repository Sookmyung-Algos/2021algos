#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

long long calc(int num){

    long long result = 0;
    for (int i = 0; i < v.size(); i++)
        result = result +  min(v[i], num);
    return result;
 }

int main(void){
    // 시간 초과
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; // 지방의 수
    cin >> n;
    vector<int> v(n);

    int maxBudget = 0;
    for (int i = 0; i < n; i++){
        cin >> v[i]; // 각 지방의 예산 요청
        maxBudget = max(maxBudget, v[i]); // 최대 예산
    }

    int m; // 총 예산
    cin >> m;

    int low = 0, high = maxBudget;
    int result;

    // 이분 탐색
    while (low <= high){

        int mid = (low + high) / 2;

        long long sum = 0;

        for (int i = 0; i < n; i++)
            sum = sum + min(v[i], mid); // 중간 값이나 지방의 최소 예산 중 적은 금액

        if (sum <= m){ // 합이 최대 예산합보다 작다면
            result = mid;
            low = mid + 1;
        }

        else // 합이 최대 예산합보다 크다면
            high = mid - 1;
    }

    cout << result << "\n";
    return 0;
}
