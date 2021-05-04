/*
 * main.c
 * Copyright (C) 2021 Roman S <romanstrah@mail.ru>
 * 
 * Practical_Lesson_2 is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * Practical_Lesson_2 is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>

#define BUFFER 5
#define DEBUG

void print_string_mem(char* string, int symbols_before, int symbols_after)
{
    printf("Output format -> Address: char [code]\n");

    for (int i = symbols_before; i > 0; i--)
    {
        printf("%d: %c [%d]\n", &string[-i], string[-i], string[-i]);
    }

    printf("-string-begin-\n");

    int j = 0;

    while (string[j] != '\0')
    {
        printf("%d: %c [%d]\n", &string[j], string[j], string[j]);
        j++;
    }

    printf("%d: %c [%d]\n", &string[j], string[j], string[j]);
    printf("-string-end-\n");

    for (int k = 1; k <= symbols_after; k++)
    {
        printf("%d: %c [%d]\n", &string[j + k], string[j + k], string[j + k]);
    }
}

int main()
{
    int ch;
    int symbols_amount = 0;
    int string_size = BUFFER;
    char* user_string = NULL;

    user_string = (char*) malloc(BUFFER * sizeof(char));

    if (user_string == NULL)
    {
        fprintf(stderr, "Memory allocation error!\n");
        return 1;
    }

    printf("Enter a string: ");

    while ((ch = getchar()) != '\n')
    {
        if (symbols_amount >= string_size - 1)
        {
            char* temp_ptr = (char*) realloc(user_string, (BUFFER + symbols_amount) * sizeof(char));

            if (temp_ptr == NULL)
            {
                fprintf(stderr, "Memory allocation error!\n");
                free(user_string);
                return 2;
            }

            user_string = temp_ptr;
        }

        user_string[symbols_amount] = ch;
        symbols_amount++;
    }

    user_string[symbols_amount] = '\0';

    printf("Entered string: %s\n", user_string);

#ifdef DEBUG
    print_string_mem(user_string, 5, 5);
#endif

    free(user_string);

    return 0;
}