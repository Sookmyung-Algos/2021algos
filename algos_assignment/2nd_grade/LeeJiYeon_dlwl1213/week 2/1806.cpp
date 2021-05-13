#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 987654321;
int arr[100001];

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, S;
    cin >> N >> S;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int l = 0, h = 0;
    int sum = arr[0];
    int result = INF;

    while (l <= h && h < N){
        if (sum < S)
            sum += arr[++h];
        else if (sum == S){
            result = min(result, (h - l + 1));
            sum += arr[++h];
        }
        else if (sum > S){
            result = min(result, (h - l + 1));
            sum -= arr[l++];
        }
    }

    if (result == INF)
        cout << 0 << "\n";
    else
        cout << result << "\n";

    return 0;
}
