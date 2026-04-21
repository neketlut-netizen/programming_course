#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>

double EPS = 1e-9;//10^-9

void GaussS1mple(double** matrix, int M, int N, int* Mass) {
    int Row = 0; // текущая строка
    for (int col = 0; col < N && Row < M; ++col) { // пока не закончиться столбцы переменных или строки
        int Swap_Row = Row;
        for (int i = Row + 1; i < M; ++i) { // ищем что ниже
            if (fabs(matrix[i][col]) > fabs(matrix[Swap_Row][col])) {
                Swap_Row = i;
            }
        }

        if (fabs(matrix[Swap_Row][col]) < EPS) {// свободная переменная
            Mass[col] = -1;
            continue;
        }

        Mass[col] = Row;

        double* temp = matrix[Row];
        matrix[Row] = matrix[Swap_Row];
        matrix[Swap_Row] = temp;


        for (int i = Row + 1; i < M; ++i) {
            if (fabs(matrix[i][col]) > EPS) {
                double diffrent = matrix[i][col] / matrix[Row][col];
                for (int j = col; j <= N; ++j) {
                    matrix[i][j] -= diffrent * matrix[Row][j];
                }
            }
        }
        Row++;
    }
}


void GaussJordan(double** matrix, int M, int N, int* Mass) {
    int Row = 0; // текущая строка
    for (int col = 0; col < N && Row < M; ++col) { // пока не закончиться столбцы переменных или строки
        int Swap_Row = Row;
        for (int i = Row + 1; i < M; ++i) { // ищем что ниже
            if (fabs(matrix[i][col]) > fabs(matrix[Swap_Row][col])) {
                Swap_Row = i;
            }
        }

        if (fabs(matrix[Swap_Row][col]) < EPS) {// свободная переменная
            Mass[col] = -1;
            continue;
        }

        Mass[col] = Row;

        double* temp = matrix[Row];
        matrix[Row] = matrix[Swap_Row];
        matrix[Swap_Row] = temp;

        double main_val = matrix[Row][col]; // значение главного элемента

        for (int i = col; i <= N; ++i) {
            matrix[Row][i] /= main_val;
        }

        for (int i = 0; i < M; ++i) {
            if (i != Row) { // пропускаем текущую строку
                double diffrent = matrix[i][col]; //коэфецент для домножения робочей строки
                for (int j = col; j <= N; ++j) {
                    matrix[i][j] -= diffrent * matrix[Row][j]; //0 во всем столбце
                }
            }
        }
        Row++;
    }
}



int main() {
    srand(time(NULL));
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

    int* Mass = new int[N];// хранение индексов строк базисных переменных
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


    //Копия мтарицы
    double** S1mpleMat = new double* [M];
    for (int i = 0; i < M; i++) {
        S1mpleMat[i] = new double[N + 1];
        for (int j = 0; j <= N; j++) {
            S1mpleMat[i][j] = matrix[i][j];
        }
    }
    int* MassCopy = new int[N];
    for (int i = 0; i < N; i++) {
        MassCopy[i] = -1;
    }

    GaussS1mple(S1mpleMat, M, N, MassCopy);
    GaussJordan(matrix, M, N, Mass);

    
    
    bool Unlucky = false; // флаг "Решений"
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

    for (int i = 0; i < M; i++) {
        for (int j = 0; j <= N; j++) {
            fprintf(file, "%.3lf ", S1mpleMat[i][j]);
        }
        fprintf(file, "\n");
    }





    if (Unlucky == true) {
        fprintf(file, "Inconsistent system");
    }
    else {
        double* Answer = new double[N];//Итоговый ответ
        if (Rank < N) {
            fprintf(file, "free value: ");
            for (int j = 0; j < N; j++) {
                if (Mass[j] == -1) {
                    fprintf(file, "x%d, ", j + 1);
                    Answer[j] = 2.000;
                }
            }
            fprintf(file, "\n");
        }


        for (int j = 0; j < N; j++) { // Зависимые перепменные
            if (Mass[j] != -1) {
                int r = Mass[j]; //строка ведущей переменной
                double val = matrix[r][N];

                for (int k = 0; k < N; k++) {
                    if (Mass[k] == -1) {
                        val -= matrix[r][k] * Answer[k]; //x1+4*x2=12 -> x1=12-4*x2
                    }
                }
                Answer[j] = val;
            }
        }


        for (int j = 0; j < N; j++) {//Выввод
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
        delete[]S1mpleMat[i];
    }
    delete[]S1mpleMat;
    delete[]matrix;
    delete[]Mass;
    delete[]MassCopy;



    return 0;
}