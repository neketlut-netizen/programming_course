#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>

int main() {
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("ERROR with FILE\n");
        return 0;
    }

    int RowMax=0;
    int ColMax = 0;
    int N = 0;
    int* Row = new int[100];
    int* Col = new int[100];
    int count = 0;

    while (count < 100 && fscanf(file, "%d %d", &Row[count], &Col[count]) == 2) count++;
    fclose(file);

    ///максимальный элемент в массиве
    for (int i = 0; i < count; i++) {
        if (RowMax < Row[i]) RowMax = Row[i];
    }
    for (int i = 0; i < count; i++) {
        if (ColMax < Col[i]) ColMax = Col[i];
    }
    if (ColMax > RowMax) N = ColMax;
    else N = RowMax;
    
    //Матрица смежности
    int size = N + 1;
    int** matrix = new int* [size];
    for (int i = 0; i < size; i++) {
        matrix[i] = new int[size];
        for (int j = 0; j < size; j++) matrix[i][j] = 0;
    }

    for (int i = 0; i < size; i++) {
        matrix[0][i] = i;
        matrix[i][0] = i;
    }
    for (int i = 0; i < count; i++) {
        matrix[Row[i]][Col[i]] = 1;
        matrix[Col[i]][Row[i]] = 1;
    }

    file = fopen("output1.txt", "w");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            fprintf(file,"%d ", matrix[i][j]);
        }
        fprintf(file,"\n");
    }
    fclose(file);
    for (int i = 0; i < size; i++) delete[] matrix[i];
    delete[] matrix;
    delete[] Row;
    delete[] Col;
    //_____________________________________________________________________________________________________________________
    FILE* FileOutput = fopen("output2.txt", "w");

    return 0;
}
