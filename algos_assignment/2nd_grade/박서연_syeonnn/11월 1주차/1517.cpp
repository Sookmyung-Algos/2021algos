//1517 (플5) 버블소트

#include <iostream>
using namespace std;

int N;
int A[500000];
int B[500000];
long long ans;

void merge(int l, int r)
{
    int mid = (l + r) / 2;
    int i = l;
    int j = mid + 1;
    int k = 0;

    while (i <= mid || j <= r)
    {
        if (i <= mid && (j > r || A[i] <= A[j])) {
            B[k++] = A[i++];
        }   
        else{
            B[k++] = A[j++];
            ans += (long long)mid - i + 1;
        }
    }

    for (int i = l; i <= r; i++) 
        A[i] = B[i - l];
}

void mergesort(int l, int r)
{
    if (l == r)
        return;

    int mid = (l + r) / 2;
    mergesort(l, mid);
    mergesort(mid + 1, r);
    merge(l, r);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) 
        cin >> A[i];

    mergesort(0, N - 1);

    cout << ans << '\n';
    return 0;
}
