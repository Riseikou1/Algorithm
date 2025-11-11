#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

struct Point {
    int row, col;
};

struct Move {
    Point dest;
    int degree;
};

Point directions[8] = {
    {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
    {1, -2}, {1, 2}, {2, -1}, {2, 1}
};

void printPath(int m, int n, const vector<vector<int>>& path) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << path[i][j] << " ";
        }
        cout << "\n";
    }
}

bool isValid(int r, int c, int m, int n, const vector<vector<int>>& board) {
    return r >= 0 && r < m && c >= 0 && c < n && board[r][c] == 0;
}

int countOnwardMoves(Point p, int m, int n, const vector<vector<int>>& board) {
    int count = 0;
    for (int i = 0; i < 8; i++) {
        int next_r = p.row + directions[i].row;
        int next_c = p.col + directions[i].col;
        if (isValid(next_r, next_c, m, n, board)) {
            count++;
        }
    }
    return count;
}

bool compareMoves(const Move& a, const Move& b) {
    return a.degree < b.degree;
}

bool solveKnightTour(int m, int n, Point cur, int move_count, vector<vector<int>>& board, vector<vector<int>>& path) {
    if (move_count == m * n) {
        return true;
    }

    vector<Move> next_moves;
    for (int i = 0; i < 8; i++) {
        int next_r = cur.row + directions[i].row;
        int next_c = cur.col + directions[i].col;

        if (isValid(next_r, next_c, m, n, board)) {
            Point next_point = {next_r, next_c};
            int degree = countOnwardMoves(next_point, m, n, board);
            next_moves.push_back({next_point, degree});
        }
    }

    sort(next_moves.begin(), next_moves.end(), compareMoves);

    for (const auto& move : next_moves) {
        Point next_p = move.dest;

        board[next_p.row][next_p.col] = 1; 
        path[next_p.row][next_p.col] = move_count + 1;

        if (solveKnightTour(m, n, next_p, move_count + 1, board, path)) {
            return true; 
        }

        board[next_p.row][next_p.col] = 0;
        path[next_p.row][next_p.col] = 0;
    }

    return false; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int m, n, start_r, start_c;
        cin >> m >> n >> start_r >> start_c;

        start_r--;
        start_c--;

        vector<vector<int>> board(m, vector<int>(n, 0));
        vector<vector<int>> path(m, vector<int>(n, 0));
        Point start_point = {start_r, start_c};

        board[start_r][start_c] = 1;
        path[start_r][start_c] = 1;

        if (solveKnightTour(m, n, start_point, 1, board, path)) {
            cout << "1\n";
            printPath(m, n, path);
        } else {
            cout << "0\n";
        }
    }
    return 0;
}