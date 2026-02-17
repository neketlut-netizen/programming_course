#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>

// алгоритм вставками
void sortArray(int* arr, int size) {
    for (int i = 1; i < size; i++) {
        for (int temp_index = i; ((temp_index > 0) && (arr[temp_index] < arr[temp_index - 1])); temp_index--) {
            int temp = arr[temp_index];
            arr[temp_index] = arr[temp_index - 1];
            arr[temp_index - 1] = temp;
        }
    }
}

int* Merge(int* arr1, int* arr2, int size1, int size2) {
    int i = 0, j = 0, k = 0, size3 = size1+size2;
    int* Res;
    Res = new int[size3];

    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            Res[k++] = arr1[i++];
        }
        else {
            Res[k++] = arr2[j++];
        }
    }

    while (i < size1) { Res[k++] = arr1[i++]; }
    while (j < size2) { Res[k++] = arr2[j++]; }

    return Res;


}

// Lab 08
// TODO: реализуйте решение по заданию в labs/lab08_pointers_arrays/README.md
//
// Рекомендация по выводу:
// - без лишнего текста
// - числа через пробел
// - если несколько строк — в фиксированном порядке
int main() {
    srand(time(NULL));
    // Упражнение 1: объяснить использование типов/переменных в коде (без ввода).
    // TODO: при необходимости вывести пояснения/результаты.

    // Упражнение 2: найти ошибки в коде (без ввода).
    // TODO: при необходимости вывести пояснения/результаты.

    // Упражнение 3: заполнить массивы (10 элементов) разными способами.
    // TODO: реализуйте 4 варианта заполнения и выведите 10 значений для каждого.
    int END=0;
    int stat1[10]{};
    int stat2[10]{};
    int *din1;
    int *din2;
    int* s2;
    int* d2;

    din1 = new int[10];
    din2 = new int[10];

    // Индексная алресация
    for (int i = 0; i != 10; i++)
    {
        stat1[i] = i * i;
        din1[i] = i * i;
    }

    // Косвенная адресация
    s2 = stat2;
    d2 = din2;
    for  (int i=0; i != 10; i++)
    {
        *d2 = i * i;
        *s2 = i * i;
        d2 += 1;
        s2 += 1;
    }
    d2 = din2;
    s2 = stat2;
    

    for (int i = 0; i < 10; i++)
    {
        std::cout << stat1[i] << " ";
    }
    std::cout << std::endl;

    
    for (int i = 0; i < 10; i++)
    {
        std::cout << *s2 << " ";
        s2 += 1;
    }
    std::cout << std::endl;


    for (int i = 0; i < 10; i++)
    {
        std::cout << din1[i] << " ";
    }
    std::cout << std::endl;


    for (int i = 0; i < 10; i++)
    {
        std::cout << *d2 << " ";
        d2 += 1;
    }
    std::cout << std::endl;

    ///3.2
    int* dinamic1;
    int* dinamic2;
    int* dinamicRes;
    int a, b;

    if (!(std::cin >> a >> b) || (a > 15) || (b > 15)) {
        return 0;
    }

    dinamic1 = new int[a];
    dinamic2 = new int[b];
    
    for (int i = 0; i < a; i++) {dinamic1[i] = (rand() % (355 + 355 + 1)) - 355;
        std::cout << dinamic1[i] << " ";}
    std::cout << std::endl;
    for (int i = 0; i < b; i++) {dinamic2[i] = (rand() % (355 + 355 + 1)) - 355;
        std::cout << dinamic2[i] << " ";}
    std::cout << std::endl << std::endl;

    sortArray(dinamic1, a);
    sortArray(dinamic2, b);

    for (int i = 0; i < a; i++) {
        std::cout << dinamic1[i] << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < b; i++) {
        std::cout << dinamic2[i] << " ";
    }
    std::cout << std::endl << std::endl;

    dinamicRes = Merge(dinamic1, dinamic2, a, b);
    
    for (int i = 0; i < a+b; i++) {
        std::cout << dinamicRes[i] << " ";
    }

    // Упражнение 4: линейный самоадресуемый список из 10 элементов.
    // TODO: сформируйте список и выведите элементы по порядку.
    
    
    
    
    
    
    return 0;
}
