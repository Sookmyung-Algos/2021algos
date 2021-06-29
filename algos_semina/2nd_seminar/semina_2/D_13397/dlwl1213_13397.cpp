#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector <int> v;

bool check(int mid) {
    int max=-1, min=10001, cnt = 1;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            min = v[i];
            max = v[i];
        }
        if (v[i] < min) 
            min = v[i];
        if (v[i] > max) 
            max = v[i];
        if (max - min > mid) // 구간의 점수가 넘어가면 새로운 구간이 시작되도록 함
        {
            cnt += 1; 
            max = v[i];
            min = v[i];
        }
    }
    if (m >= cnt)
        return true;
    else
        return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
  
    cin >> n >> m;
    v.resize(n);
    int sum = 0;
  
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        sum += v[i];
    }
    int ans=1987654321, mid, l = 0, r = sum;
  
    while (l <= r) //이분탐색
    {
        mid = (l + r) / 2; 
        if (check(mid))
        {
            r = mid - 1;
            if (mid < ans)
                ans = mid;
        }
        else
            l = mid + 1;
    }
    cout << ans;
  
    return 0;
}
