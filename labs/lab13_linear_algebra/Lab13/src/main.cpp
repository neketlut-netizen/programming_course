#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main() {
    int M, N;

    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("ERROR with FILE\n");
        return 0;
    }
    
    if (fscanf(file, "%d %d", &M, &N) != 2) {
        fclose(file);
        return 0;
    }

    std::cout << M << " " << N << "\n"; //_____________________________________незабудь убрать______________________


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


    for (int i = 0; i < M; i++) {
        for (int j = 0; j <= N; j++) {
            printf("%lf ", matrix[i][j]);
        }
        printf("\n");
    }
    


    return 0;
}
