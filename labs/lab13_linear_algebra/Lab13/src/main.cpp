#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <string>

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

    std::cout << M << " " << N;

    
    return 0;
}
