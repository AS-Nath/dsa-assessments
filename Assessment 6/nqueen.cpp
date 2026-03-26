#include <bits/stdc++.h>
using namespace std;

bool verify(vector<int>& board) {
    // Only the most recently placed queen can break the code.
    // So we only check with respect to that one. 
    // i -> row
    // board[i] -> col
    int j = board.size() - 1; 
    for (int i = 0; i < j; i++) {
        // anyway never same row 
        if (board[i] == board[j]) {
            return false; // same column 
        }
        if (abs(j - i) == abs(board[i] - board[j])) {
            return false; // diagonal 
        }
    }
    return true; 
}

void solve(int n, vector<int>& board, int& count) {
    if (board.size() == n) {
        count += 1;
        return; 
    }
    for (int c = 0; c < n; c++) {
        board.push_back(c);
        if (verify(board)) {
            solve(n, board, count);
        } 
        board.pop_back();
    }
}

int main(void) {
    int n;
    cin >> n;
    int count = 0;
    vector<int> board;
    solve(n, board, count);
    cout << count << endl;  
    return 0; 
}