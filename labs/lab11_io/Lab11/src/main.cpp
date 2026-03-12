#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>


bool isPrefix(const char* root, const char* word) {
    int i = 0;
    while (root[i] != '\0') {
        if (root[i] != word[i]) {
            return false;
        }
        i++;
    }
    return true;
}


int main() {
    char words[50][26];
    int wordCount = 0;

    FILE* fin = fopen("input.txt", "r");
    if (fin == NULL) {
        printf("ERROR with [input] file");
        return 0;
    }

    while (!feof(fin) && wordCount < 50) {
        if (fscanf(fin, "%25s", words[wordCount]) == 1) {
            wordCount++;
        }
    }
    fclose(fin);

    int longRootInd = -1;
    int longRoot = -1;

    int mostImportRootInd = -1;
    int CountMostImportRoot = 0;


    for (int i = 0; i < wordCount; ++i) {
        int currentCount = 0;

        for (int j = 0; j < wordCount; ++j) {
            if ((!(i == j)) and isPrefix(words[i], words[j])) {currentCount++;}
        }

        if (currentCount > 0) {
            int currentLength = strlen(words[i]);

            if (longRootInd == -1 or currentLength > longRoot) {
                longRoot = currentLength;
                longRootInd = i;
            }

            if (mostImportRootInd == -1 or currentCount > CountMostImportRoot) {
                CountMostImportRoot = currentCount;
                mostImportRootInd = i;
            }
        }
    }

    FILE* fout1 = fopen("output1.txt", "w");
    if (longRootInd == -1) {
        fprintf(fout1, "NO\n");
    }
    else {
        fprintf(fout1, "%s:\n", words[longRootInd]);
        for (int j = 0; j < wordCount; ++j) {
            if (longRootInd != j and isPrefix(words[longRootInd], words[j])) {
                fprintf(fout1, "%s\n", words[j]);
            }
        }
    }
    fclose(fout1);

    FILE* fout2 = fopen("output2.txt", "w");
    if (mostImportRootInd == -1) {
        fprintf(fout2, "NO\n");
    }
    else {
        fprintf(fout2, "%s %d\n", words[mostImportRootInd], CountMostImportRoot);
    }
    fclose(fout2);

    std::cout << "successful completed" << std::endl;

    return 0;
}
