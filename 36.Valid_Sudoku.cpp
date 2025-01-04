#include <bits/stdc++.h>
using namespace std;

// time complexity: O(n^2)
// space complexity: O(1)

class Solution {
  public:
    bool validColumn(vector<vector<char>> &board, int column, int digit) {
        int digitCount = 0;
        for (int i = 0; i < 9; i++) {
            if (board[i][column] != '.' && board[i][column] == digit) {
                digitCount++;
            }
        }
        return digitCount == 1;
    }

    bool validRow(vector<vector<char>> &board, int row, int digit) {
        int digitCount = 0;
        for (int i = 0; i < 9; i++) {
            if (board[row][i] != '.' && board[row][i] == digit) {
                digitCount++;
            }
        }
        return digitCount == 1;
    }

    bool validQuadrant(vector<vector<char>> &board, int digit, int row, int column) {
        int digitCount = 0;
        int startRow = (row / 3) * 3;
        int startColumn = (column / 3) * 3;
        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startColumn; j < startColumn + 3; j++) {
                if (board[i][j] != '.' && board[i][j] == digit) {
                    digitCount++;
                }
            }
        }
        return digitCount == 1;
    }

    bool isValidSudoku(vector<vector<char>> &board) {

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    continue;
                } else if (validRow(board, i, board[i][j]) && validColumn(board, j, board[i][j]) && validQuadrant(board, board[i][j], i, j)) {
                    continue;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
