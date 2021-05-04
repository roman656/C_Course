/*
 * messenger.h
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

#ifndef MESSENGER_H_INCLUDED
#define MESSENGER_H_INCLUDED

/*----------Библиотеки----------*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*------------------------------*/

/*-----------Макросы------------*/
#define MAX_AUTHOR_NAME_LENGTH 30
#define MAX_TEXT_LENGTH 255
#define BUFFER 16
/*------------------------------*/

/*-----------Структуры----------*/
typedef struct message
{
    time_t time;
    char author[MAX_AUTHOR_NAME_LENGTH];
    char text[MAX_TEXT_LENGTH];
    struct message* next;
} MESSAGE;
/*------------------------------*/

/*------Функции-и-процедуры-----*/
MESSAGE* create_message(time_t time, char* author, char* text);
void print_message(MESSAGE* message);
char* read_string(int max_length);
MESSAGE* read_message();
MESSAGE* add_message_to_list(MESSAGE* root, MESSAGE* new_message);
void print_all_messages(MESSAGE* root);
void free_messages(MESSAGE* root);
int save_messages_to_file(MESSAGE* root, char* filename);
MESSAGE* load_messages_from_file(char* filename);
/*------------------------------*/

#endif // MESSENGER_H_INCLUDED