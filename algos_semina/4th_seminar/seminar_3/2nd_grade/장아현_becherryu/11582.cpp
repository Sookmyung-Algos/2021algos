//개별합병정렬
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, grade, k;
	vector <int> score;
	vector <int> st;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> grade;
		score.push_back(grade);
	}

	cin >> k;
	int p = n / k;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		st.push_back(score[i]);
		count++;
		if (count == p)
		{
			sort(st.begin(), st.end());
			int j = 0;
			while (true)
			{
				cout << st[j] << " ";
				j++;
				if (j == p)
				{
					count = 0;
					st.clear();
					j = 0;
					break;
				}
			}

		}
	}
}
