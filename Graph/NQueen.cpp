#include <iostream>
using namespace std;

int board[20], n;

bool isSafe(int row, int col) {
    for (int i = 1; i < row; i++) {
        // Check column & diagonals
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return false;
    }
    return true;
}

void solve(int row) {
    if (row > n) {
        // Print solution
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (board[i] == j) cout << "Q ";
                else cout << ". ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    for (int col = 1; col <= n; col++) {
        if (isSafe(row, col)) {
            board[row] = col;   // Place queen
            solve(row + 1);     // Move to next row
        }
    }
}

int main() {
    cout << "Enter number of queens: ";
    cin >> n;
    solve(1);
    return 0;
}
