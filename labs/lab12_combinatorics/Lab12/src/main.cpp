#include <iostream>
#include <cmath>
// Lab 12
int count1 = 0;
int count2 = 0;

// 1 в лоб column - столбец row - строка
void print(int** board, int k) {
    std::cout << "[";
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            if (board[i][j] == 1) {
                std::cout << j + 1;
                if (i < k - 1) { std::cout << ","; }
                break;
            }
        }
    }
    std::cout << "]" << std::endl;
}

void print2(int* pos, int k) {
    std::cout << "[";
    for (int i = 0; i < k; i++) {
        std::cout << pos[i] + 1;
        if (i < k - 1) std::cout << ",";
    }
    std::cout << "]";
}

//________________________________________________________________________________________________________________________

bool isSafe(int** board1, int row, int col, int k) {
    for (int i = 0; i < row; i++) {
        if (board1[i][col] == 1) return false;
    }

    for (int i = row, j = col; i >= 0 and j >= 0; i--, j--) {
        if (board1[i][j] == 1) return false;
    }

    for (int i = row, j = col; i >= 0 and j < k; i--, j++) {
        if (board1[i][j] == 1) return false;
    }

    return true;
}

void Matrix(int** board1, int row, int k) {
    if (row == k) {
        count1++;
        print(board1, k);
        return;
    }

    for (int col = 0; col < k; col++) {
        if (isSafe(board1, row, col, k)) {
            board1[row][col] = 1;
            Matrix(board1, row + 1, k);
            board1[row][col] = 0;
        }
    }
}

//___________________________________________________________________________________________________________________
bool SafeOpt(int* pos, int row, int col) {
    for (int i = 0; i < row; i++) {
        if (pos[i] == col or abs(pos[i] - col) == abs(row - i)) {
            return false;
        }
    }
    return true;
}

void slove(int* pos, int row, int k) {
    if (row == k) {
        count2++;
        print2(pos, k);
        std::cout << std::endl;
        return;
    }

    for (int col = 0; col < k; col++) {
        if (SafeOpt(pos, row, col)) {
            pos[row] = col;
            slove(pos, row + 1, k);
        }
    }
}

int main() {
    int k;
    std::cin >> k;
    if (k <= 0) {
        std::cout << "Error Missing k" << std::endl;
        return 0;
    }

    int** board1 = new int* [k];
    for (int i = 0; i < k; i++){
        board1[i] = new int[k];
        for (int j = 0; j < k; j++) {
            board1[i][j] = 0;
        }
    }

    int* board2 = new int[k];

    Matrix(board1, 0, k);
    std::cout << count1 << std::endl;

    slove(board2, 0, k);
    std::cout << count2 << std::endl;

    return 0;
}
