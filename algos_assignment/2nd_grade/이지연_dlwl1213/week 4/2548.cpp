#include<stdio.h>
#include<math.h>

int arr[20001];
int calc(int num, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += abs(arr[i] - num);
    return sum;
}
int main()
{
    int n, max = 0, min = 10001,temp, dif = 0x7fffffff, a;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] > max)max = arr[i];
        if (arr[i] < min)min = arr[i];
    }
    for (int i = min; i <= max; i++) {
        temp = calc(i, n);
        if (temp < dif) {
            dif = temp;
            a = i;
        }
    }
    printf("%d\n", a);
    return 0;
}
