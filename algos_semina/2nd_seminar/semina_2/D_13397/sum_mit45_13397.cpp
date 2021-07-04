#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector <int> v;

bool check(int mid)
{
    // 범위 외의 숫자
    int max_num = -1, min_num = 10001, cnt = 1;

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            min_num = v[i]; // 첫 번째 값을 최소값으로
            max_num = v[i]; // 첫 번째 값을 최대값으로
        }

        if (v[i] < min_num) // 최솟값 갱신
            min_num = v[i];
        
        if (v[i] > max_num) // 최댓값 갱신
            max_num = v[i];
       
        if (max_num - min_num > mid) // 구간의 점수가 넘어가면
        {
            cnt += 1; // 새로운 구간 시작
            max_num = v[i];
            min_num = v[i];
        }
    }
    if (m >= cnt)
        return true;
    else
        return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n >> m; // 배열의 크기
    v.resize(n);
    int sum = 0;

    // 배열에 들어가 있는 수 입력
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        sum += v[i];
    }

    int ans = 99999999, mid, left = 0, right = sum;
    while (left <= right) // // 구간의 점수값 이분탐색
    {
        mid = (left + right) / 2;
        if (check(mid))
        {
            right = mid - 1;
            if (mid < ans)
                ans = mid;
        }
        else
            left = mid + 1;
    }
    cout << ans;
    return 0;
}
