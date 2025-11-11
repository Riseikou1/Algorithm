#include <iostream>
#include <vector>
#include <algorithm> // Needed for std::sort

using namespace std;

// --- Data Structures ---
struct Point {
    int row, col;
};

// A struct to hold a potential move and its "degree" (number of onward moves)
struct Move {
    Point dest;
    int degree;
};

// The 8 possible moves for a knight
Point directions[8] = {
    {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
    {1, -2}, {1, 2}, {2, -1}, {2, 1}
};


// --- Helper Functions ---
void printPath(int m, int n, const vector<vector<int>>& path) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << path[i][j] << " ";
        }
        cout << "\n";
    }
}

// Checks if a square is on the board and unvisited
bool isValid(int r, int c, int m, int n, const vector<vector<int>>& board) {
    return r >= 0 && r < m && c >= 0 && c < n && board[r][c] == 0;
}

// Counts valid onward moves from a given square (calculates its "degree")
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

// Comparison function to sort moves by their degree in ascending order
bool compareMoves(const Move& a, const Move& b) {
    return a.degree < b.degree;
}


// --- Core Recursive Function with Warnsdorff's Rule ---
bool solveKnightTour(int m, int n, Point cur, int move_count, vector<vector<int>>& board, vector<vector<int>>& path) {
    // BASE CASE: If all squares are visited, we're done!
    if (move_count == m * n) {
        return true;
    }

    // WARNSDORFF'S RULE IMPLEMENTATION
    // 1. Find all valid next moves from the current position
    vector<Move> next_moves;
    for (int i = 0; i < 8; i++) {
        int next_r = cur.row + directions[i].row;
        int next_c = cur.col + directions[i].col;

        if (isValid(next_r, next_c, m, n, board)) {
            Point next_point = {next_r, next_c};
            // 2. For each valid move, count *its* onward moves (its degree)
            int degree = countOnwardMoves(next_point, m, n, board);
            next_moves.push_back({next_point, degree});
        }
    }

    // 3. Sort the next moves by degree (fewest onward moves first)
    sort(next_moves.begin(), next_moves.end(), compareMoves);

    // 4. Explore the moves in the optimized order
    for (const auto& move : next_moves) {
        Point next_p = move.dest;

        // Choose
        board[next_p.row][next_p.col] = 1; // Mark as visited
        path[next_p.row][next_p.col] = move_count + 1;

        // Explore
        if (solveKnightTour(m, n, next_p, move_count + 1, board, path)) {
            return true; // Solution found!
        }

        // Unchoose (Backtrack) - this happens far less often now
        board[next_p.row][next_p.col] = 0;
        path[next_p.row][next_p.col] = 0;
    }

    return false; // No solution from this path
}


// --- Main Function ---
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int m, n, start_r, start_c;
        cin >> m >> n >> start_r >> start_c;

        // Adjust for 0-based indexing as per problem description [cite: 3, 4]
        start_r--;
        start_c--;

        vector<vector<int>> board(m, vector<int>(n, 0));
        vector<vector<int>> path(m, vector<int>(n, 0));
        Point start_point = {start_r, start_c};

        // Initialize starting position
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

