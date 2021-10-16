#include <iostream>
#include <algorithm>
using namespace std;

struct tmp{
    int b, p, q, r;
};

bool cmp(tmp x, tmp y) {
    if (x.p * x.q * x.r == y.p * y.q * y.r) {
        if (x.p + x.q + x.r == y.p + y.q + y.r)
            return x.b < y.b;
        return (x.p + x.q + x.r) < (y.p + y.q + y.r);
    }
    return x.p * x.q * x.r < y.p * y.q * y.r;
}

int main() {
    int n;
    scanf("%d", &n);
    tmp person[101];
    for (int i = 0; i < n; ++i)
        scanf("%d%d%d%d", &person[i].b, &person[i].p, &person[i].q, &person[i].r);
    sort(person, person + n, cmp);
    printf("%d %d %d", person[0].b, person[1].b, person[2].b);
}
