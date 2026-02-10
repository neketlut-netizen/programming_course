#include <iostream>
#include <math.h>
#include <stdio.h>
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

    std::cout << "1" << " " << sin(x0) / x0 << std::endl;

    score = (4 - x0) / 10;
    
    //Инициализатор, Условие, Итерация
    for (int i = 2; i != 12; i++)
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
    long long s = 0;
    long long start = 0;
    long long next = 1;
    long long time = 0;
    int count = 1;
    if (!(std::cin >> max_value)) {
        return 0;
    }

    while (s < max_value)
    {
        time = next;
        next = next + start;
        start = time;
        count++;
        s = s + start;
    }

    if (s == max_value) {std::cout << count << " " << s << std::endl;}
    else {std::cout << count-1 << " " << s-start << std::endl;}


    // TODO: вычислите N и S (S <= MAX) и выведите результаты.


// 3 Задание
    int countcent = 1, timer;
    double summa, cent, r, somecent, nextcent, nextpay;
    if (scanf_s("%lf %d %lf", &summa, &timer, &cent) != 3) {
        return 0;
    }

    r = cent / (12 * 100); // Процентная ставка
    somecent = summa / timer; //доля основного процента
    
    nextcent = summa * r; //проценты любого долга
    nextpay = somecent + nextcent; //любой платёж

    printf("%d %lf %lf %lf\n", countcent, summa, nextcent, nextpay);
    while (countcent != timer) {
        summa = summa - somecent;
        nextcent = summa * r;
        nextpay = somecent + nextcent;
        countcent++;
        printf("%d %lf %lf %lf\n", countcent, summa, nextcent, nextpay);
    }



    char end = 0;
    if (!(std::cin >> end)) {
        return 0;
    }

    return 0;
}
