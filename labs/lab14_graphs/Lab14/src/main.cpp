#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>

int main() {
    // ================================================================================================================================================
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("ERROR with input.txt\n");
        return 0;
    }

    int N = 0; 
    int* Row = new int[100];
    int* Col = new int[100];
    int count = 0;

    
    while (count < 100 && fscanf(file, "%d %d", &Row[count], &Col[count]) == 2) {
        if (Row[count] > N) N = Row[count];
        if (Col[count] > N) N = Col[count];
        count++;
    }
    fclose(file);

    int size = N + 1;
    int** matrix = new int* [size];
    for (int i = 0; i < size; i++) {
        matrix[i] = new int[size];
        for (int j = 0; j < size; j++) matrix[i][j] = 0;
    }

    
        for (int i = 0; i < count; i++) {
            matrix[Row[i]][Col[i]] = 1;
            matrix[Col[i]][Row[i]] = 1;
        }

    FILE* fileOut1 = fopen("output1.txt", "w");
    fprintf(fileOut1, "%d\n", N);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            fprintf(fileOut1, "%d ", matrix[i][j]);
        }
        fprintf(fileOut1, "\n");
    }
    fclose(fileOut1);

    for (int i = 0; i < size; i++) delete[] matrix[i];
    delete[] matrix; delete[] Row; delete[] Col;


    // ___________________________________________________________________________________________________________________________________________________
    FILE* fileIn2 = fopen("output1.txt", "r");
    
    fscanf(fileIn2, "%d", &N); 

    matrix = new int* [N + 1];
    for (int i = 1; i <= N; i++) {
        matrix[i] = new int[N + 1];
        for (int j = 1; j <= N; j++) {
            fscanf(fileIn2, "%d", &matrix[i][j]);
        }
    }
    fclose(fileIn2);

    int* L = new int[N + 1]; // Кол-во инцидентных дуг с вершиной
    int* S = new int[N + 1]; // Индексы начала
    for (int j = 1; j <= N; j++) L[j] = 0;

    
    int Edge = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (matrix[i][j] == 1) {
                L[i]++;
                Edge++;
            }
        }
    }

    S[1] = 0;
    for (int j = 2; j <= N; j++) {
        S[j] = S[j - 1] + L[j - 1];
    }

    int* D = new int[Edge];
    int* U = new int[N + 1]; // Дополнительный массив, дублирующий индексы
        for (int j = 1; j <= N; j++) U[j] = S[j];

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (matrix[i][j] == 1) {
                    D[U[i]] = j;
                    U[i]++;
                }
            }
        }

    FILE* fileOut2 = fopen("output2.txt", "w");
    fprintf(fileOut2, "%d %d\n", N, Edge);
    for (int i = 1; i <= N; i++) fprintf(fileOut2, "%d ", L[i]); fprintf(fileOut2, "\n");
    for (int i = 1; i <= N; i++) fprintf(fileOut2, "%d ", S[i]); fprintf(fileOut2, "\n");
    for (int i = 0; i < Edge; i++) fprintf(fileOut2, "%d ", D[i]); fprintf(fileOut2, "\n");
    fclose(fileOut2);

    for (int i = 1; i <= N; i++) delete[] matrix[i];
    delete[] matrix; delete[] U;


    // ___________________________________________________________________________________________________________________________________________________
    FILE* fileIn3 = fopen("output2.txt", "r");

    fscanf(fileIn3, "%d %d", &N, &Edge);
    for (int i = 1; i <= N; i++) fscanf(fileIn3, "%d", &L[i]);
    for (int i = 1; i <= N; i++) fscanf(fileIn3, "%d", &S[i]);
    for (int i = 0; i < Edge; i++) fscanf(fileIn3, "%d", &D[i]);
    fclose(fileIn3);

    FILE* fileOut3 = fopen("output3.txt", "w");

    for (int i = 1; i <= N; i++) {
            for (int k = S[i]; k < S[i] + L[i]; k++) {
                int j = D[k];
                if (i < j) {
                    fprintf(fileOut3, "%d %d\n", i, j);
                }
            }
    }
    fclose(fileOut3);
    delete[] L; delete[] S; delete[] D;
    return 0;
}