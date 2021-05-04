/*
 * main.c
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

int main()
{
    int exit_code = 0;
    char is_exiting = 0;
    MESSAGE* root_message = NULL;
    char* users_choice = NULL;
    char* filename = NULL;

    while (!is_exiting)
    {
        printf("\nMain menu:\n"
               "1 - Add new message to list\n"
               "2 - Save all messages to file\n"
               "3 - Load messages from file\n"
               "4 - Show all messages\n"
               "5 - Exit\n"
               "Your choice: ");

        users_choice = read_string(2);

        if (users_choice == NULL)
        {
            fprintf(stderr, "main(): memory allocation error in read_string()!\n");
            exit_code = 1;
            break;
        }

        switch(users_choice[0])
        {
            case '1':
            {
                MESSAGE* temp = read_message();

                /*
                  * Даже если произошли проблемы при создании
                  * нового сообщения - даем возможность попробовать
                  * что-либо сделать (например, сохранить имеющиеся сообщения).
                 */
                if (temp != NULL)
                {
                    root_message = add_message_to_list(root_message, temp);
                }
                else
                {
                    exit_code = 2;
                }

                break;
            }
            case '2':
            {
                printf("\nEnter the file name (with .txt or others): ");

                filename = read_string(255);

                if (filename == NULL)
                {
                    fprintf(stderr, "main(): memory allocation error in read_string()!\n");
                    exit_code = 3;
                    break;
                }

                printf("\nSaving...\n");

                if (save_messages_to_file(root_message, filename) != 0)
                {
                    printf("Saving error!\n");
                    exit_code = 4;
                }
                else
                {
                    printf("Saved.\n");
                }

                free(filename);

                break;
            }
            case '3':
            {
                printf("\nEnter the file name (with .txt or others): ");

                filename = read_string(255);

                if (filename == NULL)
                {
                    fprintf(stderr, "main(): memory allocation error in read_string()!\n");
                    exit_code = 5;
                    break;
                }

                printf("\nLoading...\n");

                MESSAGE* temp = load_messages_from_file(filename);

                if (temp == NULL)
                {
                    printf("Loading error!\n");
                    exit_code = 6;
                }
                else
                {
                    free_messages(root_message);
                    root_message = temp;
                    printf("Loaded.\n");
                }

                free(filename);
                
                break;
            }
            case '4':
            {
                print_all_messages(root_message);
                break;
            }
            case '5':
            {
                is_exiting = 1;
                printf("\nExiting...\n");
                break;
            }
            default:
            {
                while (getchar() != '\n');
                printf("Wrong input! Try again.\n");
            }
        }

        free(users_choice);
    }

    free_messages(root_message);

    return exit_code;
}