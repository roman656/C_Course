/*
 * main.c
 * Copyright (C) 2021 Roman S <romanstrah@mail.ru>
 * 
 * Practical_Lesson_1 is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * Practical_Lesson_1 is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>

int main()
{
    int number;
    
    printf("Enter a natural number: ");

    while ((scanf("%d", &number) != 1) || (number <= 0) || (getchar() != '\n'))
    {
        while (getchar() != '\n');
        fprintf(stderr, "Wrong input!\nEnter a positive number: ");
    }

    printf("Number was: %d\nNew number is: ", number);

    while (number != 0)
    {
        printf("%d", number % 10);
        number = number / 10;
    }
    
    return 0;
}
