#include <stdio.h>
#define N 100001

void Sort(int a[], int b[], int l, int r) {
    int i = l, j = r;
    int p = a[(l + r) / 2];
    int q;
    do
    {
        while (a[i] < p)
            i++;
        while (a[j] > p)
            j--;
        if (i <= j)
        {
            q = a[i];
            a[i] = a[j];
            a[j] = q;
            q = b[i];
            b[i] = b[j];
            b[j] = q;
            i++;
            j--;
        }
    } while (i <= j);

    if (l < j)
        Sort(a, b, l, j);

    if (i < r)
        Sort(a, b, i, r);
}

int main(void)
{
	int x[N], y[N];
	int a;
	scanf("%d", &a);
	for (int i = 0; i < a; i++) {
		scanf("%d%d", &x[i], &y[i]);
	}
    Sort(x, y, 0, a - 1);

    while (1) {
        int count = 0;
        for (int i = 0; i < a - 1; i++) {
            if (x[i] == x[i + 1]) {
                if (y[i] > y[i + 1]) {
                    count++;
                    int temp;
                    temp = y[i + 1];
                    y[i + 1] = y[i];
                    y[i] = temp;
                }
            }
        }
        if (count == 0) break;
    }

    for (int i = 0; i < a; i++) printf("%d %d\n", x[i], y[i]);
	return 0;
}
