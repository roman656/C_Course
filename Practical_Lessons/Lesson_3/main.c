/*
 * main.c
 * Copyright (C) 2021 Roman S <romanstrah@mail.ru>
 * 
 * Practical_Lesson_3 is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * Practical_Lesson_3 is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ELEMENTS_AMOUNT 10
#define MAX_VALUE 10

void init_array(int input_array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        input_array[i] = rand() % (MAX_VALUE + 1);
    }
}

void print_array(int input_array[], int size)
{
    printf("[");

    for (int i = 0; i < size; i++)
    {
        printf("%d, ", input_array[i]);
    }

    printf("\b\b]\n");
}

void bubble_sorting(int input_array[], int size)
{
    int temp;
    char was_swap = 0;

    for (int i = size - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (input_array[j] > input_array[j + 1])
            {
                temp = input_array[j];
                input_array[j] = input_array[j + 1];
                input_array[j + 1] = temp;
                
                was_swap = 1;
            }
        }

        if (!was_swap)
        {
            break;
        }

        was_swap = 0;
    }
}

int main()
{
    int array[ELEMENTS_AMOUNT] = {0};

    srand(time(NULL));

    init_array(array, ELEMENTS_AMOUNT);

    printf("Unsorted array: ");
    print_array(array, ELEMENTS_AMOUNT);

    bubble_sorting(array, ELEMENTS_AMOUNT);

    printf("Sorted array:   ");
    print_array(array, ELEMENTS_AMOUNT);

    return 0;
}