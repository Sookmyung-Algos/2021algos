#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} point;

point sort[100001];

void merge(point* arr, int first, int mid, int end) {
    int i, j, k;
    i = first;
    j = mid + 1;
    k = first;

    while (i <= mid && j <= end) {
        if (arr[i].x < arr[j].x)
            sort[k++] = arr[i++];
        else if (arr[i].x > arr[j].x)
            sort[k++] = arr[j++];
        else {
            if (arr[i].y < arr[j].y)
                sort[k++] = arr[i++];
            else if (arr[i].y > arr[j].y)
                sort[k++] = arr[j++];
        }
    }

    if (i <= mid) {
        while (i <= mid) 
            sort[k++] = arr[i++];
    }
    else {
        while (j <= end) 
            sort[k++] = arr[j++];
    }
    for (k = first; k <= end; k++)
        arr[k] = sort[k];
}

void mergesort(point* arr, int first, int end) {
    int mid;
    if (first < end) {
        mid = (first + end) / 2;
        mergesort(arr, first, mid);
        mergesort(arr, mid + 1, end);
        merge(arr, first, mid, end);
    }
}

int main(void) {
    int n;
    scanf("%d", &n);

    point* arr = (point*)malloc(sizeof(point)*n);
    for(int i = 0; i < n; i++)
        scanf("%d %d", &arr[i].x, &arr[i].y);
    
    mergesort(arr, 0, n-1);
    for (int i = 0; i < n; i++)
        printf("%d %d\n", arr[i].x, arr[i].y);

    return 0;
}
