#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int board[9][9];

vector<pair<int, int>> v;

bool solve(int num, int row, int col) {
    int x, y;

    for (int j = 0; j < 9; j++) {
        if (num == board[row][j] || num == board[j][col])    
            return false;
    }

    x = int(row / 3) * 3;
    y = int(col / 3) * 3;

    for (int i = x; i < (x + 3); i++) {
        for (int j = y; j < (y + 3); j++) {
            if (num == board[i][j])  
                return false;
        }
    }
    return true;
}

void play(int idx) {
    if ((size_t)idx == v.size()) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        exit(0);
        return;
    }

    int row = v[idx].first, col = v[idx].second;

    for (int i = 1; i < 10; i++) {
        if (solve(i, row, col)) {
            board[row][col] = i;  
            play(idx + 1);  
        }
    }
    board[row][col] = 0;
    return;
}

int main() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++)
            if (board[i][j] == 0)  v.push_back(make_pair(i, j));
    }
    play(0);
    return 0;
}
