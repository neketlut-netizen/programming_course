#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>


// Lab 09
// TODO: реализуйте решение по заданию в labs/lab09_strings/README.md
//
// Рекомендация по выводу:
// - без лишнего текста
// - числа через пробел
// - если несколько строк — в фиксированном порядке
int main() {
    // Упражнения 1–3: демонстрация/анализ строковых функций (без ввода).
    // TODO: добавьте примеры и вывод результатов.

    char str1[80] = "Radmir Renatovich ";
    char str2[15] = "Best professor";
    char str3[40];

    // кол-во байт в строке
    std::cout << "1.strlen() \n" << "1.1 " << strlen(str1) << "\n" << "1.2 " << strlen(str2) << "\n\n";

    // копирует символы из одной строки в другую
    std::cout << "2.strcpy()\n";
    strcpy(str3, str1);
    std::cout << str3 << '\n';
    strncpy(str3, str2, 20); // опред. кол-во символов
    std::cout << str3 << "\n\n";

    // объединяет 2 строки в 1
    std::cout << "3.strcat()\n";
    strcat(str1, str2);
    std::cout << str1 << "\n\n";

    
    std::string s1 = "I want ";
    std::string s2 = "MONEY";
    std::string s3;


    std::cout << "4.length()\n4.1 " << s1.length() << "\n4.2 " << s2.length() << "\n\n"; //подсчёт символов

    //добавление в первую строку, вторую строку
    std::cout << "5.append\n";
    s3.append(s1);
    s3.append(s2);
    std::cout << s3 << "\n\n";

    //Удаление строки(поз., кол-во)
    std::cout << "6.erase()\n";
    s3.erase(7, 5).append("Love");
    std::cout << s3 << "\n\n";


    // Упражнение 4: ввод количества слов и самих слов.
    int word_count = 0;
    if (!(std::cin >> word_count) || word_count>20 || word_count<=0) {
        return 0;
    }

    char words1[20][11]; //двумерный массив

    std::vector<std::string> words; //дин. массив
    words.reserve(word_count);


    std::cin.ignore();
    for (int i = 0; i < word_count; ++i) {
        std::string word;
        if (!(getline(std::cin, word))) {  
            return 0;
        }
        

        if (word.length() > 10) {
            word = word.substr(0, 10);
        }

        strcpy(words1[i], word.c_str()); //из str в "массив символов"
        words.push_back(word);
    }
    
   

    std::cout << "\n";

    for (int i = 0; i < word_count; i += 2) {
        std::cout << "1." << i << ". " << words1[i] << std::endl;
    }

    std::cout << "\n";

        for (int i = 0; i < word_count; i += 2) {
        std::cout << "2." << i << ". " << words[i] << std::endl;
    }

    // TODO: выведите слова с четными номерами (2, 4, 6, ...), по одному в строке.
    return 0;
}


/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <Windows.h>




int main() {
    std::vector<std::string> Rus;
    std::vector<std::string> Eng;

    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("ERROR with [input] file\n");
        return 0;
    }

    char buffer1[100];
    char buffer2[100];
    
    while (fscanf(file, "%99s %99s", buffer1, buffer2) == 2) {
        Rus.push_back(buffer1);
        Eng.push_back(buffer2);
    }
    
    
    fclose(file);
    
    
    std::string command, target;
    

    
    //начало программы:
    while (std::cin >> command) {
        if (command == "EXIT") {
            break;
        }

        // Добавление
        if (command == "ADD") {
            std::string word, translation;
            
            if (std::cin >> word >> translation) {
                Rus.push_back(word);
                Eng.push_back(translation);
                FILE* file_app = fopen("input.txt", "a");

                if (file_app != NULL) {
                    fprintf(file_app, "\n%s %s", word.c_str(), translation.c_str());
                    fclose(file_app);
                    std::cout << "OK" << std::endl;
                }
                
                else {
                    std::cout << "FILE_ERROR" << std::endl;
                }
            }
        }




        // Перевод
        if (command == "TRANSLATE") {
            if (!(std::cin >> target)) break;
            
            bool found = false;

            //1. для Ru->Eng
            for (size_t i = 0; i < Rus.size(); i++) {
                if (Rus[i] == target) {
                    std::cout << "TRANSLATION " << Eng[i] << std::endl;
                    found = true;
                    break;
                }
            }

            //2. для Eng->Ru        
            if (!found) {
                for (size_t i = 0; i < Eng.size(); i++) {
                    if (Eng[i] == target) {
                        std::cout << "TRANSLATION " << Rus[i] << std::endl;
                        found = true;
                        break;
                    }
                }
            }

            if (!found) {
                std::cout << "NOT_FOUND" << std::endl;
            }
        }
    }




    return 0;
}*/
