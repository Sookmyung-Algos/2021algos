#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector <int> v;
    int n, ans;

    scanf("%d", &n);
    v.resize(n);

    // 벡터에 입력
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    sort(v.begin(), v.end()); // 정렬

    if (n % 2)
        ans = v[n / 2];
    else
    {
        if (v[n / 2] > v[n / 2 - 1])
            ans = v[n / 2 - 1];
        else
            ans = v[n / 2];
    }

    printf("%d", ans);
    return 0;
}
