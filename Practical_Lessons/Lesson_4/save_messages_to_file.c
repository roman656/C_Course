/*
 * save_messages_to_file.c
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

int save_messages_to_file(MESSAGE* root, char* filename)
{
    FILE* fileptr = NULL;

    fileptr = fopen(filename, "w");

    if (fileptr == NULL)
    {
        fprintf(stderr, "save_messages_to_file(): fopen() error!\n");
        return 1;
    }

    MESSAGE* temp = root;

    while (temp != NULL)
    {
        if (fwrite(temp, sizeof(MESSAGE), 1, fileptr) != 1)
        {
            fprintf(stderr, "save_messages_to_file(): fwrite() error!\n");
            fclose(fileptr);
            return 2;
        }

        temp = temp->next;
    }

    fclose(fileptr);

    return 0;
}