#include <iostream>
#include <vector>
using namespace std;

int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int dfs(vector<vector<char>>& grid, int r, int c){
    if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == '.'){
        return 0;
    }
    int res = 1;
    grid[r][c] = '.';
    for(int i = 0; i < 4; i++){
        res += dfs(grid, r + directions[i][0], c + directions[i][1]);
    }
    return res;
}

int main(){
    int w; cin >> w;
    while(w--){
        int rows, cols; cin >> rows >> cols;
        vector<vector<char>> temuujin(rows, vector<char>(cols, '.'));
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                cin >> temuujin[r][c];
            }
        }
        int area = 0;
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(temuujin[r][c] == '#') 
                    area = max(area, dfs(temuujin, r, c));
            }
        }
        cout << area << "\n";
    }
    return 0;
}