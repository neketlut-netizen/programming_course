#include <iostream>
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

void PackArr(int* base_arr, int size, int* second_arr) {
    bool opt;
    for (int i = 0; i < size; i++) {
        opt = false;
        for (int j = 0; (j < 18 && opt == false); j++) {
            if (base_arr[i] == j) {
                second_arr[j]++;
                opt = true;
            }
        }
    }
}

void UnpackArr(int* base_arr, int size, int* second_arr){
    long long pos = 0;
    for (int i = 0; i < 18; i++) {
        while (second_arr[i] > 0) {
            base_arr[pos] = i;
            pos++;
            second_arr[i]--;
        }
    }
}


int main() {
    srand(time(NULL));
    
    long long size;
    int array2[18]{0};
    int CheckArr[18]{0};

    size = 1500 + (rand() % (2000 - 1500 + 1));
    int* array1 = new int[size];

    for (int i = 0; i < size; i++){
        array1[i] = rand() % 18;
    }
    sortArray(array1, size);

    
    PackArr(array1,size,array2);
    for (int i = 0; i < 18; i++) {
        std::cout << array2[i] << " ";
    }
    std::cout << "\n";
    delete[]array1;
    array1 = new int[size];


    UnpackArr(array1, size, array2);

    
    PackArr(array1, size, CheckArr);
    for (int i = 0; i < 18; i++) {
        std::cout << CheckArr[i] << " ";
    }
    delete[]array1;

    return 0;
}
