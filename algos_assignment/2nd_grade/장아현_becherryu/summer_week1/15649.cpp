#include <iostream>
using namespace std;

int n, m;
int arr[10];
bool isused[10]; //사용되었는지 확인

void func(int a)
{
	if (a == m)
	{
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (!isused[i])
		{
			arr[a] = i;
			isused[i] = 1;
			func(a + 1);
			isused[i] = 0;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	func(0);	
}
