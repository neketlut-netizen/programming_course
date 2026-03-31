#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cmath>

double EPS = 1e-9;

void GaussJordan(double** matrix, int M, int N, int* Mass) {
    int Row = 0;
    for (int col = 0; col < N && Row < M; ++col) {
        int Swap_Row = Row;
        for (int i = Row + 1; i < M; ++i) {
            if (fabs(matrix[i][col]) > fabs(matrix[Swap_Row][col])) {
                Swap_Row = i;
            }
        }

        if (fabs(matrix[Swap_Row][col]) < EPS) {
            Mass[col] = -1;
            continue;
        }

        Mass[col] = Row;

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

    int* Mass = new int[N];
    for (int i = 0; i < N; i++) {
        Mass[i] = -1;
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

    GaussJordan(matrix, M, N, Mass);

    bool Unlucky = false;
    int Rank = 0;
    for (int i = 0; i < M; i++) {
        bool all_0 = true;
        for (int j = 0; j < N; j++) {
            if (fabs(matrix[i][j]) > EPS) {
                all_0 = false;
                break;
            }
        }
        if (all_0 && (fabs(matrix[i][N]) > EPS)) {
            Unlucky = true;
            break;
        }
        if (all_0 == false) { 
            Rank++; 
        }
    }

    file = fopen("input.txt", "a");
    fprintf(file, "\n");

    if (Unlucky == true) {
        fprintf(file, "Inconsistent system");
    }
    else {
        double* Answer = new double[N];
        if (Rank < N) {
            fprintf(file, "free value: ");
            for (int j = 0; j < N; j++) {
                if (Mass[j] == -1){
                    fprintf(file, "x%d, ", j + 1);
                    Answer[j] = 1.0;
                }
            }
            fprintf(file, "\n");
        }


        for (int j = 0; j < N; j++) {
            if (Mass[j] != -1) {
                int r = Mass[j];
                double val = matrix[r][N];

                for (int k = 0; k < N; k++) {
                    if (Mass[k] == -1) {
                        val -= matrix[r][k] * Answer[k];
                    }
                }
                Answer[j] = val;
            }
        }

        for (int j = 0; j < N; j++) {
            double res = Answer[j];
            if (fabs(res) < EPS) {
                res = 0.0;
            }
            fprintf(file, "x%d=%.3lf; ", j + 1, res);
        }
        delete[] Answer;
    }
    
    fclose(file);

    for (int i = 0; i < M; i++) {
        delete[]matrix[i];
    }
    delete[]matrix;
    delete[]Mass;
    


    return 0;
}
