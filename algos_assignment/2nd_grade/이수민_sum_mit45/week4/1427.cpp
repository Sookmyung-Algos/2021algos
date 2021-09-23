#include <iostream>
#include <string>
using namespace std;

void insertion_sort(string& n)
{
    int i, j;
    for (int i = 1; i < n.size(); i++)
    {
        auto key = n[i];

        // 내림차순 정렬
        for (j = i - 1; j >= 0 && n[j] < key; j--)
        {
            n[j + 1] = n[j];
        }
        n[j + 1] = key;
    }
}

int main()
{
    string n;
    cin >> n;

    insertion_sort(n);

    cout << n;

    return 0;
}
