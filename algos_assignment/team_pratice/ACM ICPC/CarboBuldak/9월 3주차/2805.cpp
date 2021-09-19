//2805(실버3) 나무 자르기

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int N;
long long M;  // int아님
int tree[1000001];
int high = 1, low = 0;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;  // 나무의 수 N, 집으로 가져가려는 나무의 길이 M

    for (int i = 0; i < N; i++)
    {
        cin >> tree[i];
        high = max(high,tree[i]);
    }

    int ans = 0;

    // 이분탐색
    while (low <= high)
    {
        int mid = (low + high) / 2; // 절단기의 높이

        long long sum = 0;    // 집에 가져갈 수 있는 나무의 길이 합, int 아님
        for (int i = 0; i < N; i++) 
        {
            if (tree[i] - mid > 0)
                sum += tree[i] - mid;
        } 

        if (sum >= M)
        {
            ans = max(ans, mid);    // M미터 나무를 집에 가져갈 수 있을 때 절단기에 설정 가능한 높이 최댓값
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
  
    cout << ans << '\n';
    return 0;
}
