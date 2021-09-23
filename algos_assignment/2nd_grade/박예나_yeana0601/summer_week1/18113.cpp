#include <iostream>
#include <algorithm>
using namespace std;

int n, k, m, l;
int ans = -1;
int arr_l = 0;
int arr[1000001];
int max_l = 0;

bool check(int p) {
  int count = 0;
  for (int i = 0; i < arr_l; ++i) {
    if (arr[i] < p) break;
    count += arr[i] / p;
    if (count >= m)
      return true;
  }
  return count >= m;
}

void bisect(int start, int end) {
  if (start > end) return;
  int mid = (start + end) / 2;
  if (check(mid)) {
    ans = mid;
    bisect(mid + 1, end);
  } 
    else bisect(start, mid - 1);
};

int main() {
  cin >> n >> k >> m;
  for (int i = 0; i < n; ++i) {
    cin >> l;
    if (l <= k) continue;
    else {
      if (l >= 2 * k) l -= 2 * k;
      else l -= k;
      arr[arr_l++] = l;
      max_l = max(max_l, l);
    }
  }
  sort(arr, arr + arr_l, greater<int>());
  bisect(1, max_l);
  cout << ans << "\n";
  return 0;
}
