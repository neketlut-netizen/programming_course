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
    int N = 0; //Длинна квадратной матрицы
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
    delete[] matrix; delete[] Row; delete[] Col; count = 0; N = 0; RowMax = 0; ColMax = 0; size = 0;
    //__________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
    FILE* FileOutput = fopen("output2.txt", "w"); 
    file = fopen("output1.txt", "r");
    int MaxSize = 0;
    size = -1;

    while (fscanf(file, "%d", &MaxSize) == 1) {
        if (MaxSize > size) size = MaxSize;
    }

    fclose(file);
    file = fopen("output1.txt", "r");

    matrix = new int* [size + 1];
    for (int i = 0; i < size + 1; i++) {
        matrix[i] = new int[size + 1];
        for (int j = 0; j < size + 1; j++) {
            fscanf(file, "%d", &matrix[i][j]);
        }
    }


    for (int i = 1; i < size + 1; i++) {
        for (int j = 1; j < size + 1; j++) {
            if (matrix[i][j] == 1) {
                fprintf(FileOutput, "%d ", j);
            }
        }
        fprintf(FileOutput, "\n");
    }

    for (int i = 0; i < size; i++) delete[] matrix[i];
    fclose(file); fclose(FileOutput); size = 0; MaxSize = 0;
    //____________________________________________________________________________________________________________________________________
    file = fopen("output2.txt", "r");
    FileOutput = fopen("output3.txt", "w");
    RowMax = 1; //номер тякущей строки
    int neighbor;
    char c;

    while (fscanf(file, "%d", &neighbor) == 1) {
        if (RowMax < neighbor) {
            fprintf(FileOutput, "%d %d\n", RowMax, neighbor);
        }
        while (fscanf(file, "%c", &c) == 1) {
            if (c == '\n') {
                RowMax++;
                break;
            }
            if (c != ' ' && c != '\r') {
                ungetc(c, file);//вернуть обратно
                break;
            }
        }
    }

    fclose(file); fclose(FileOutput);
    return 0;
}
