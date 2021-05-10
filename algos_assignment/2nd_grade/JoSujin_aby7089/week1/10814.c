#include <stdio.h>
#include <stdlib.h>

typedef struct person {
    int age;
    char name[102];
    int join;
}person;
struct person p[100000];
int cmp(const void *left, const void *right) {
    const person *a = (const person *)left;
    const person *b = (const person *)right;

    if (a->age == b->age) {
        if (a->join < b->join)
            return -1;
        else
            return 1;
    }
    else
        if (a->age > b->age)
            return 1;
        else
            return -1;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {                        //입력받기
        scanf("%d %s", &p[i].age, p[i].name);
        p[i].join = i;
    }

    qsort(p, n, sizeof(person), cmp);

    for (int i = 0; i < n; i++) {
        printf("%d %s\n", p[i].age, p[i].name);
    }
}
