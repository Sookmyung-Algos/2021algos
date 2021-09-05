// 11582 치킨 TOP N
// 정렬

#include <iostream>
using namespace std;

int a[1048577]; int b[1048577];
int N, cnt, limit;

void merge(int start, int end) {
    if (end-start > N/limit) return;
    
    int mid = (start+end) / 2;
    int i=start,j = mid+1,k=0;
    
    while (i <= mid && j <= end) {
        if (a[i] <= a[j]) b[k++] = a[i++];
        else b[k++] = a[j++];
    }
    
    while (i <= mid) b[k++] = a[i++];
    while (j <= end) b[k++] = a[j++];
    
    for (int i=start;i<=end;i++) {
        a[i] = b[i - start];
    }
}

void merge_sort(int start, int end) {
    if (start == end) return;
    int mid = (start + end) / 2;
    merge_sort(start, mid);
    merge_sort(mid + 1, end);
    merge(start, end);
}

int main() {
    /* 입력 */
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> a[i];
    }
    cin >> limit;
    
    /* 정렬 */
    merge_sort(0,N-1);
    
    /* 출력 */
    for (int i=0;i<N;i++) {
        cout << a[i] << " ";
    }
    return 0;
}
