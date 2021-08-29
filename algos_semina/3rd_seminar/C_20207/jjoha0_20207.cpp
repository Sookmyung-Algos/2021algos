#include <iostream>
#include <algorithm>

using namespace std;

struct info
{
    int start;
    int end;
};
int maxH[366];
info calendar[1005];
bool busy[1005][366];

bool operator<(const info &a, const info &b)
{
    if (a.start == b.start)
        return a.end > b.end;
    return a.start < b.start;
}

int main(void)
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> calendar[i].start >> calendar[i].end;
        
    sort(calendar, calendar+N);
    
    for (int i = 0; i < N; i++)
    {
        info schedule = calendar[i];
        int row = 1;
        
        while (row <= N)
        {
            if(busy[row][schedule.start])
                row++;
            else
                break;
        }
        for (int j = schedule.start; j <= schedule.end; j++)
        {
            busy[row][j] = true;
            maxH[j] = max(maxH[j], row);
        }
    }
    
    int width = 0;
    int height = 0;
    int area = 0;
    for (int i = 1; i < 366; i++)
    {
        
        if (maxH[i])
        {
            width++;
            height = max(maxH[i], height);
        }
        else{
            area += width*height;
            width = 0;
            height = 0;
        }
    }
    area += height * width;
    cout << area << '\n';
}
