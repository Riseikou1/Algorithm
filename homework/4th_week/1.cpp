#include <bits/stdc++.h>
using namespace std;
int tile_id = 1;

void tile(vector<vector<int>>& board, int row, int col, int size,
          int hole_row, int hole_col) {
    if (size == 2) {
        // Base case: fill 2x2 block with one tromino
        for (int i = row; i < row + 2; i++) {
            for (int j = col; j < col + 2; j++) {
                if (i == hole_row && j == hole_col) continue;
                board[i][j] = tile_id;
            }
        }
        tile_id++;
        return;
    }

    int mid = size / 2;
    int center_row = row + mid;
    int center_col = col + mid;

    // Quadrants: (top-left, top-right, bottom-left, bottom-right)
    // Determine which quadrant contains the real hole
    int quad = 0;
    if (hole_row < center_row && hole_col < center_col) quad = 0;         // top-left
    else if (hole_row < center_row && hole_col >= center_col) quad = 1;   // top-right
    else if (hole_row >= center_row && hole_col < center_col) quad = 2;   // bottom-left
    else quad = 3;                                                        // bottom-right

    // Place one tromino in the center covering the three quadrants without the real hole
    int cur_id = tile_id++;
    if (quad != 0) board[center_row - 1][center_col - 1] = cur_id; // top-left quadrant fake hole
    if (quad != 1) board[center_row - 1][center_col]     = cur_id; // top-right
    if (quad != 2) board[center_row][center_col - 1]     = cur_id; // bottom-left
    if (quad != 3) board[center_row][center_col]         = cur_id; // bottom-right

    // Recurse into all 4 quadrants
    // Top-left
    if (quad == 0)
        tile(board, row, col, mid, hole_row, hole_col);
    else
        tile(board, row, col, mid, center_row - 1, center_col - 1);

    // Top-right
    if (quad == 1)
        tile(board, row, center_col, mid, hole_row, hole_col);
    else
        tile(board, row, center_col, mid, center_row - 1, center_col);

    // Bottom-left
    if (quad == 2)
        tile(board, center_row, col, mid, hole_row, hole_col);
    else
        tile(board, center_row, col, mid, center_row, center_col - 1);

    // Bottom-right
    if (quad == 3)
        tile(board, center_row, center_col, mid, hole_row, hole_col);
    else
        tile(board, center_row, center_col, mid, center_row, center_col);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, r, c;
        cin >> n >> r >> c;

        vector<vector<int>> board(n, vector<int>(n, 0));
        board[r][c] = 0; // hole marked as 0
        tile_id = 1;

        tile(board, 0, 0, n, r, c);

        // Print the board
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }

    return 0;
}
