#include <stdio.h>

int Max(int a, int b) {
    int c;
    while (b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int min(int a, int b) {
    return a * b / Max(a, b);
}

int main(void) {
    int in[5];
    scanf("%d %d %d %d %d", &in[0], &in[1], &in[2], &in[3], &in[4]);

    int v = in[0] * in[1] * in[2];
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            for (int k = j + 1; k < 5; k++) {
                int value = min(in[i], in[j]);
                value = min(value, in[k]);
                if (v > value) {
                    v = value;
                }
            }
        }
    }

    printf("%d", v);
    return 0;
}
