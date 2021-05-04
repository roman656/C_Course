/*
 * create_message.c
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

MESSAGE* create_message(time_t time, char* author, char* text)
{
    MESSAGE* message = NULL;

    message = (MESSAGE*) malloc(sizeof(MESSAGE));

    if (message == NULL)
    {
        return message;
    }

    message->time = time;

    int i = 0;

    while ((author[i] != '\0') && (i < MAX_AUTHOR_NAME_LENGTH - 1))
    {
        message->author[i] = author[i];
        i++;
    }

    message->author[i] = '\0';

    int j = 0;

    while ((text[j] != '\0') && (j < MAX_TEXT_LENGTH - 1))
    {
        message->text[j] = text[j];
        j++;
    }

    message->text[j] = '\0';

    message->next = NULL;

    return message;
}