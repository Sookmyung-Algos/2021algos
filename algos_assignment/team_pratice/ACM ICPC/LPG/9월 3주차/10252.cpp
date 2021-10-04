#include<bits/stdc++.h>
using namespace std;

int sudoku[9][9];
bool row[9][10];
bool col[9][10];
bool square[9][10];

void dfs(int tmp){
	int x = tmp / 9;
    int y = tmp % 9;
    
    if (tmp == 81){
		for (int i = 0; i <= 9; i++){
        	for (int j = 0; j < 9; j++) {
				cout << sudoku[i][j] << " ";
			}
			cout << "\n";
        }
        exit(0);
    }
 
    if (sudoku[x][y] == 0){
        for (int i = 1; i < 9; i++){
            if (row[x][i] == false && col[y][i] == false && square[(x / 3) * 3 + (y / 3)][i] == false){
                row[x][i] = true;
                col[y][i] = true;
                square[(x / 3) * 3 + (y / 3)][i] = true;

                sudoku[x][y] = i;
                dfs(tmp + 1);

                sudoku[x][y] = 0;
                row[x][i] = false;
                col[y][i] = false;
                square[(x / 3) * 3 + (y / 3)][i] = false;
            }
        }
    }
    else dfs(tmp + 1);

}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);

	for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            cin >> sudoku[i][j];

            if (sudoku[i][j] != 0){
                row[i][sudoku[i][j]] = true;
                col[j][sudoku[i][j]] = true;
                square[(i / 3) * 3 + (j / 3)][sudoku[i][j]] = true;
            }
        }
    }

	dfs(0);

	return 0;
}