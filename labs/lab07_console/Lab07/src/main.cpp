#include <iostream>
#include <math.h>
// Lab 07
// TODO: реализуйте решение по заданию в labs/lab07_console/README.md
//
// Рекомендация по выводу:
// - без лишнего текста
// - числа через пробел
// - если несколько строк — в фиксированном порядке
int main() {
    setlocale(LC_ALL, "Russian");

    // Задание 1: вычисление значений функции.
    // Ввод: x0 — начальная точка интервала.
    double score;
    double x0 = 0.0;
    // проверка на идиота
    if (!(std::cin >> x0) || (x0 <= 0) || (x0 >= 4)) {
        return 0;
    }
    
    score = (4 - x0) / 10;
 
    //Инициализатор, Условие, Итерация
    for (int i = 1; i != 11; i++)
    {
        x0 = x0 + score;
        std::cout << i << " " << sin(x0) / x0 << std::endl;
    }

    // dfdfdf
    // // dfd/df
    // /dfdfd
    // TODO: вычислите и выведите 10 значений функции на (0, 4].



    // Задание 2: сумма чисел Фибоначчи.
    // Ввод: MAX — ограничение на сумму.
    long long max_value = 0;
    if (!(std::cin >> max_value)) {
        return 0;
    }

    // TODO: вычислите N и S (S <= MAX) и выведите результаты.
    return 0;
}
