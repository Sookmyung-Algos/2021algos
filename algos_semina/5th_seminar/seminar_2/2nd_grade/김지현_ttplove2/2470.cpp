#include <iostream>
#include <algorithm>
using namespace std;

int N;
long long n1 = -1, n2 = -1;
long long arr[100001];

void find(int s, int e)
{
    long long maxsum = 2000000000;
    while (s < e) {
        int sum = arr[s] + arr[e];
        if (abs(sum) < maxsum) {
            n1 = arr[s];
            n2 = arr[e];
            maxsum = abs(sum);
        }
        if (sum > 0) {
            e--;
        }
        else {
            s++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    find(0, N - 1);
    cout << n1 << " " << n2 << "\n";
    return 0;
}
