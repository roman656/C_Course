/*
 * read_string.c
 * Copyright (C) 2021 Roman S <romanstrah@mail.ru>
 * 
 * Practical_Lesson_4 is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * Practical_Lesson_4 is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "messenger.h"

char* read_string(int max_length)
{
    int ch;
    int symbols_amount = 0;
    int string_size = BUFFER;
    char* string = NULL;

    string = (char*) malloc(BUFFER * sizeof(char));

    if (string == NULL)
    {
        return NULL;
    }

    while (((ch = getchar()) != '\n') && (symbols_amount < max_length - 1))
    {
        if (symbols_amount >= string_size - 1)
        {
            char* temp_ptr = (char*) realloc(string, (BUFFER + symbols_amount) * sizeof(char));

            if (temp_ptr == NULL)
            {
                free(string);
                return NULL;
            }

            string = temp_ptr;
        }

        string[symbols_amount] = ch;
        symbols_amount++;
    }

    string[symbols_amount] = '\0';

    return string;
}