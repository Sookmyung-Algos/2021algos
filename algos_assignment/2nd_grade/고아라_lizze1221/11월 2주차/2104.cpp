#include <iostream>
#include <algorithm>
using namespace std;

int N;
int A[1000001];
 
long long GetMax(int from, int to){
    if (from == to) return (long long)A[from] * A[from];
 
    int mid = (from + to) / 2;
    long long leftSum = GetMax(from, mid);
    long long rightSum = GetMax(mid + 1, to);
 
    long long maxValue = max(leftSum, rightSum);
 
    int left = mid;
    int right = mid + 1;
 
    long long sum = A[left] + A[right];
    long long minValue = min(A[left], A[right]);
    maxValue = max(maxValue, sum * minValue);
 
    while (left > from || right < to){
        if (right < to && (left == from || A[left - 1] < A[right + 1])){
            sum += A[++right];
            minValue = min(minValue, (long long)A[right]);
        }
        else{
            sum += A[--left];
            minValue = min(minValue, (long long)A[left]);
        }
        long long crossSum = sum * minValue;
       
        maxValue = max(maxValue, crossSum);
    }
    return maxValue;
}
 
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
 
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];
 
    cout << GetMax(1, N);
 
    return 0;
}
