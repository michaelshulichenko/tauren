/*
    Быстрая сортировка Хоара(ОБМЕН) и Сортировка методом Шелла(ВСТАВКА), по возрастанию
    Массивы на 10, 100, 1000, 10000 элементов.
    Провести сравнение используя 3 вида массивов отсортированные по:
        возрастанию;
        убыванию;
        не отсортированный;
    Оценить их эффективность по трем параметрам: 
        время;
        количество присваиваний;
        количество сравнений;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> // Для вычисления времени выполнения

#include "hoar.h"
#include "shell.h"

/***********************************************************************/
unsigned int * create_random_array(unsigned int count) {
    clock_t start_t, end_t;
    start_t = clock();

    unsigned int i;

    // Выделение памяти под массив
    int *array = malloc( sizeof(int) * count );
    
    // Инициализация генератора случайных чисел
    srand( (unsigned)time(NULL) );

    for ( i = 0; i <= count; i++ ) {
        array[i] = rand();
    }

    end_t = clock();
    double total_t = difftime(end_t,start_t);

    // printf("Random array generation of %i elements took: %0.2f ms\n", count, total_t);

    return array;
}

// вспомогательная функция для сортировки по возрастанию через qsort()
int int_cmp_asc(const void *a, const void *b) { 
    const int *ia = (const int *)a; // casting pointer types 
    const int *ib = (const int *)b;
    return *ia  - *ib; 
    /* integer comparison: returns negative if b > a 
    and positive if a > b */ 
} 

// вспомогательная функция для сортировки по убыванию через qsort()
int int_cmp_desc(const void *b, const void *a) { 
    const int *ia = (const int *)a; // casting pointer types 
    const int *ib = (const int *)b;
    return *ia  - *ib; 
    /* integer comparison: returns negative if b > a 
    and positive if a > b */ 
} 

/***********************************************************************/
void sort_and_bench(int *array, int count, char alg[], char dir[]) {

    unsigned int array_size = sizeof(int) * count;
    
    // Все действия производить с копией массива элементов
    int *array_copy = malloc( array_size );
    memcpy( array_copy, array, array_size );

    // Отсортировать массив по возрастанию или убыванию
    if ( strcmp( dir, "asc") == 0 ) {
        qsort ( array_copy, count, sizeof(int), int_cmp_asc );
    } else if ( strcmp( dir, "desc") == 0 ) {
        qsort ( array_copy, count, sizeof(int), int_cmp_desc );
    }

    time_t start_t, end_t;
    int total_t;
    int *result;

    // Запомнить время когда сортировка началась
    start_t = clock();

    if ( strcmp(alg, "hoare") == 0 ) {
        result = hoar_sort(array_copy, 0, count);
    } else {
        result = shellsort(array_copy, count);
    }
    // Запомнить время когда сортировка закончилась
    end_t = clock();

    // Вычислить время выполнения
    total_t = difftime( end_t,start_t );

    // printf("%s\t%s\t%d\t%d\t%d\t%d\n", alg, dir, count, result[0], result[1], total_t );

    printf("\"%s\",\"%s\",\"%d\",\"%d\",\"%d\",\"%d\"\r\n", alg, dir, count, result[0], result[1], total_t );

    return;
}

/***********************************************************************/
void process(int *array, int count) {
    /* Сортировка Хоара массива отсортированного по возрастанию */
    sort_and_bench(array, count, "hoare", "asc");

    /* Сортировка Хоара массива отсортированного по убыванию */
    sort_and_bench(array, count, "hoare", "desc");

    /* Сортировка Хоара несортированого массива */
    sort_and_bench(array, count, "hoare", "random");


    /* Сортировка Шеллом массива отсортированного по возрастанию */
    sort_and_bench(array, count, "shell", "asc");

    /* Сортировка Шeллом массива отсортированного по убыванию */
    sort_and_bench(array, count, "shell", "desc");

    /* Сортировка Шелла несортированого массива */
    sort_and_bench(array, count, "shell", "random");
    
    return;
}

/***********************************************************************/
void main() {

    printf("\"Алгоритм сортировки\",\"Сортировка исходного массива\",\"Количество элементов\",\"Присваиваний\",\"Сравнений\",\"Время выполнения (мс)\"\r\n");

    process( create_random_array( 10000 ), 10000 );
    process( create_random_array( 1000 ), 1000 );
    process( create_random_array( 100 ), 100 );
    process( create_random_array( 10 ), 10 );
    
    return;
}




