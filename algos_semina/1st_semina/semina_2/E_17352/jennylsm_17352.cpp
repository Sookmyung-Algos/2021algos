#include <iostream>
#include <algorithm>
using namespace std;

int n;
int p[300001];
int arr[2];
int k;
int find(int a)
{
	if (p[a] == a)
		return a;
	return p[a] = find(p[a]);
}
void uni(int a, int b)
{
	int x(find(a));
	int y(find(b));
	if (x > y)
		p[x] = y;
	else
	{
		p[y] = x;
		if (x == y)
			p[y] = p[y] + 1;
	}
}
void in(int a)
{
	for (int i = 1; i <= a; i++)
		p[i] = i;
}
int main()
{
	cin >> n;
	in(n);
	for (int i = 0; i < n - 2; i++)
	{
		int x1, x2;
		cin >> x1 >> x2;
		uni(x1, x2);
	}
	for (int i = 1; i <= n; i++)
	{
		if (p[i] == i)
			arr[k++] = i;
	}
	cout << arr[0] << " " << arr[1];
}
