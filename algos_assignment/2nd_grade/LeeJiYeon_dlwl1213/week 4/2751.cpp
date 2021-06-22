#include <iostream>

using namespace std;

void merge(int* arr, int* sortedArr, int begin, int mid, int end) {
    int sorted = begin;
    int i = begin;
    int j = mid+1;


    while (i <= mid && j <= end) {
        if (arr[i] < arr[j]) sortedArr[sorted] = arr[i++];
        else  sortedArr[sorted] = arr[j++];

        sorted++;
    }
  
    if (i > mid) {
        while (j <= end) {
            sortedArr[sorted++] = arr[j++];
        }
    }

    if (j > end) {
        while (i <= mid) {
            sortedArr[sorted++] = arr[i++];
        }
    }

    for (int k = begin; k <= end; k++) arr[k] = sortedArr[k];

}

void mergeSort(int* arr, int* sortedArr, int begin, int end) {
    int mid;
    if (begin<end) {
        middle = (begin + end) / 2;
        mergeSort(arr, sortedArr, begin, mid);
        mergeSort(arr, sortedArr, mid + 1, end);
        merge(arr, sortedArr, begin, mid, end);
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int* sortedArr = new int[n];
    mergeSort(arr, sortedArr, 0, n-1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << '\n';

    return 0;
}
