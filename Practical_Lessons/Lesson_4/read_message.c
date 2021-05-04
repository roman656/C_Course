/*
 * read_message.c
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

MESSAGE* read_message()
{
    char* author = NULL;
    char* text = NULL;

    printf("\nEnter your name: ");
    author = read_string(MAX_AUTHOR_NAME_LENGTH);

    if (author == NULL)
    {
        fprintf(stderr, "read_message(): memory allocation error in read_string()!\n");
        return NULL;
    }

    printf("Enter your message: ");
    text = read_string(MAX_TEXT_LENGTH);

    if (text == NULL)
    {
        fprintf(stderr, "read_message(): memory allocation error in read_string()!\n");
        free(author);
        return NULL;
    }

    MESSAGE* message = create_message(time(NULL), author, text);

    free(author);
    free(text);

    if (message == NULL)
    {
        fprintf(stderr, "read_message(): memory allocation error in create_message()!\n");
        return NULL;
    }

    return message;
}