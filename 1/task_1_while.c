/*

Вариант 6, задание 1

Обчислити значення функції, якщо а змінюється від апоч до акін із кроком а.
Результат обчислень вивести у вигляді таблиці. У випадку, якщо обчислення функції неможливе,
видати повідомлення, при якому значенні  а не має розв’язку.
Вихідними даними задатися самостійно (апоч – від’ємне число, акін -додатне).
Написати два варіанти програми з for і while.

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float calculateValue(int value) {
    float result = pow(value, M_PI) / ( 1 + ( value * sqrt(value) ) );
    return result;
}

int main() {
    int aStart, aEnd, aStep = 0;

    printf("Please, specify a(min), a(max) and a(step) values (space separated) and press <Enter>\n");
    scanf("%d %d %d", &aStart, &aEnd, &aStep);

    if ( aStart > aEnd ) {
        printf("Incorrect range\n");
        return 1;
    }

    printf("Value\t\tResult\n");

    while( aStart <= aEnd ) {
        float result = calculateValue(aStart);

        if ( isnan(result) ) {
            printf("a = %d\t\tNo solution for this value\n", aStart);
        } else {
            printf("a = %d\t\t%.2f\n", aStart, result);
        }
        aStart += aStep;
    }

    return 0;
}
