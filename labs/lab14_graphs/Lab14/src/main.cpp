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

    int Edge;
    int N; 
    fscanf(file, "%d %d", &N, &Edge);
    int* Row = new int[Edge];
    int* Col = new int[Edge];
    int count = 0;
    
    while (count < Edge && fscanf(file, "%d %d", &Row[count], &Col[count]) == 2) {
        count++;
    }
    fclose(file);

    for (int i = 0; i < Edge; i++) {
        if (Row[i] <= 0 or Col[i] <= 0) {
            printf("Error in Input file, Vertex must be > 0");
            file = fopen("output1.txt", "w"); fclose(file); file = fopen("output2.txt", "w");
            fclose(file); file = fopen("output3.txt", "w"); fclose(file); return 0;
        }
    }

    int size = N + 1;
    int** matrix = new int* [size];
    for (int i = 0; i < size; i++) {
        matrix[i] = new int[size];
        for (int j = 0; j < size; j++) matrix[i][j] = 0;
    }

    
        for (int i = 0; i < count; i++) {
            if ((matrix[Row[i]][Col[i]] == 1) or (matrix[Col[i]][Row[i]] == 1)) {
                printf("Error 2 Edge on 2 Vertex");
                return 0;
            }
            matrix[Row[i]][Col[i]] = 1;
            matrix[Col[i]][Row[i]] = 1;
        }

    FILE* fileOut1 = fopen("output1.txt", "w");
    fprintf(fileOut1, "%d %d\n", N, Edge);
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
     
    fscanf(fileIn2, "%d %d", &N, &Edge);

    matrix = new int* [N + 1];
    for (int i = 1; i <= N; i++) {
        matrix[i] = new int[N + 1];
        for (int j = 1; j <= N; j++) {
            fscanf(fileIn2, "%d", &matrix[i][j]);
        }
    }
    fclose(fileIn2);

    int* L = new int[N + 1]; // Кол-во соседних вершин
    int* S = new int[N + 1]; // Индексы начала
    for (int j = 1; j <= N; j++) L[j] = 0;

    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (matrix[i][j] == 1) {
                L[i]++;
            }
        }
    }

    S[1] = 0;
    for (int j = 2; j <= N; j++) {
        S[j] = S[j - 1] + L[j - 1];
    }

    int* D = new int[Edge*2];
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
    for (int i = 0; i < Edge*2; i++) fprintf(fileOut2, "%d ", D[i]); fprintf(fileOut2, "\n");
    fclose(fileOut2);

    for (int i = 1; i <= N; i++) delete[] matrix[i];
    delete[] matrix; delete[] U;


    // ___________________________________________________________________________________________________________________________________________________
    FILE* fileIn3 = fopen("output2.txt", "r");

    fscanf(fileIn3, "%d %d", &N, &Edge);
    for (int i = 1; i <= N; i++) fscanf(fileIn3, "%d", &L[i]);
        for (int i = 1; i <= N; i++) fscanf(fileIn3, "%d", &S[i]);
        for (int i = 0; i < Edge*2; i++) fscanf(fileIn3, "%d", &D[i]);
    fclose(fileIn3);

    FILE* fileOut3 = fopen("output3.txt", "w");

    fprintf(fileOut3, "%d %d\n", N, Edge);
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