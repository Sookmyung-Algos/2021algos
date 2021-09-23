#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct member {
    int age, cnt;
    char name[100];
}mem[100000];

bool cmp(struct member m1, struct member m2) {
    if (m1.age == m2.age) return (m1.cnt < m2.cnt);
    else return (m1.age < m2.age);
}

int main(int argc, const char* argv[]) {
    int n = 0;
    scanf_s("%d", n);
    printf("\n");
        for (int i = 0; i < n; i++) {
            scanf_s("%d %s", mem[i].age, mem[i].name);
            printf("\n");
                mem[i].cnt = i;
        }
    sort(mem, mem + n, cmp);

    for (int j = 0; j < n; j++) printf("%d %s", mem[j].age, mem[j].name);
}
