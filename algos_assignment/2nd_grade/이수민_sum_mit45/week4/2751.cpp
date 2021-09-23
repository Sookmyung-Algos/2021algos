#include <iostream>
using namespace std;

// 합병정렬
void merge(int* arr, int* sortedArr, int begin, int middle, int end) {
    int sortedInd = begin;
    int i = begin;
    int j = middle + 1;

    while (i <= middle && j <= end) {
        if (arr[i] < arr[j]) sortedArr[sortedInd] = arr[i++];
        else  sortedArr[sortedInd] = arr[j++];

        sortedInd++;
    }

    //왼쪽이 오른쪽보다 모두 작은 경우
    if (i > middle) {
        while (j <= end) {
            sortedArr[sortedInd++] = arr[j++];
        }
    }
    //오른쪽이 왼쪽보다 모두 작은 경우
    if (j > end) {
        while (i <= middle) {
            sortedArr[sortedInd++] = arr[i++];
        }
    }

    for (int k = begin; k <= end; k++) arr[k] = sortedArr[k];

}

void mergeSort(int* arr, int* sortedArr, int begin, int end) {
    int middle;
    if (begin < end) {
        middle = (begin + end) / 2;
        mergeSort(arr, sortedArr, begin, middle);
        mergeSort(arr, sortedArr, middle + 1, end);
        merge(arr, sortedArr, begin, middle, end);
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
    mergeSort(arr, sortedArr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << '\n';

    return 0;
}
