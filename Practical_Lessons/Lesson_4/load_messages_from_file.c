/*
 * load_messages_from_file.c
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

MESSAGE* load_messages_from_file(char* filename)
{
    FILE* fileptr = NULL;

    fileptr = fopen(filename, "r");

    if (fileptr == NULL)
    {
        fprintf(stderr, "load_messages_from_file(): fopen() error!\n");
        return NULL;
    }

    /* Определение размера файла. */
    fseek(fileptr, 0, SEEK_END);
    long file_size = ftell(fileptr);
    rewind(fileptr);

    int messages_amount = file_size / sizeof(MESSAGE);

    MESSAGE* root = NULL;
    MESSAGE* temp = NULL;

    for (int i = 0; i < messages_amount; i++)
    {
        if (i != 0)
        {
            temp->next = (MESSAGE*) malloc(sizeof(MESSAGE));
            temp = temp->next;
        }
        else
        {
            temp = (MESSAGE*) malloc(sizeof(MESSAGE));
            root = temp;
        }

        if (temp == NULL)
        {
            fprintf(stderr, "load_messages_from_file(): memory allocation error!\n");
            free_messages(root);
            fclose(fileptr);
            return NULL;
        }

        if (fread(temp, sizeof(MESSAGE), 1, fileptr) != 1)
        {
            fprintf(stderr, "load_messages_from_file(): fread() error!\n");
            free_messages(root);
            fclose(fileptr);
            return NULL;
        }

        temp->next = NULL;
    }

    fclose(fileptr);

    return root;
}