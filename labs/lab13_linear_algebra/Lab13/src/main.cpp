#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cmath>

void GaussJordan(double** matrix, int M, int N) {
    int Row = 0;
    for (int col = 0; col < N && Row < M; ++col) {
        int Swap_Row = Row;
        for (int i = Row + 1; i < M; ++i) {
            if (fabs(matrix[i][col]) > fabs(matrix[Swap_Row][col])) {
                Swap_Row = i;
            }
        }

        double* temp = matrix[Row];
        matrix[Row] = matrix[Swap_Row];
        matrix[Swap_Row] = temp;

        double main_val = matrix[Row][col];

        for (int i = col; i <= N; ++i) {
            matrix[Row][i] /= main_val;
        }

        for (int i = 0; i < M; ++i) {
            if (i != Row) {
                double diffrent = matrix[i][col];
                for (int j = col; j <= N; ++j) {
                    matrix[i][j] -= diffrent * matrix[Row][j];
                }
            }
        }
        Row++;
    }
}



int main() {
    int M, N;

    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("ERROR with FILE\n");
        return 0;
    }
    
    if (fscanf(file, "%d %d", &M, &N) != 2) { // M и N
        fclose(file);
        return 0;
    }



    //создание двойного массива и заполнение (lf - double)
    double** matrix = new double* [M]; 
    for (int i = 0; i < M; i++) {
        matrix[i] = new double[N + 1];
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j <= N; j++) {
            fscanf(file, "%lf", &matrix[i][j]);
        }
    }
    fclose(file);

    GaussJordan(matrix, M, N);

    
    


    return 0;
}
