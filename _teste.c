/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _teste.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:31:18 by gneto-co          #+#    #+#             */
/*   Updated: 2023/10/11 16:25:21 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//clear && cc *.c *.h -Wall -Wextra -Werror -lbsd && ./a.out
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <bsd/string.h>
#include "libft.h"



int testar(int i)
{
    char c = 0;
    int n = 0;
    int n2 = 0;
    char str0[100];
    char str[100];
    char str2[100];
    char *str_p;
    char *result_ft;
    char *result_orig;
    
    switch (i)
    {
        case 0:
            return 1;
            break;
            
        #pragma region 1-12

        case 1:
            printf("\033]0;isalpha\007");

            printf("\nInsert a char: ");
            scanf(" %c", &c);
            printf("\nft_isalpha function return: %d", ft_isalpha(c));
            printf("\noriginal function return: %d", isalpha(c));
            break;

        case 2:
            printf("\033]0;isdigit\007");
            
            printf("\nInsert a char: ");
            scanf(" %c", &c);
            printf("\nft_isdigit function return: %d", ft_isdigit(c));
            printf("\noriginal function return: %d", isdigit(c));
            break;
            
        case 3:
            printf("\033]0;isalnum\007");

            printf("\nInsert a char: ");
            scanf(" %c", &c);
            printf("\nft_isalnum function return: %d", ft_isalnum(c));
            printf("\noriginal function return: %d", isalnum(c));
            break;

        case 4:
            printf("\033]0;isascii\007");
            
            printf("Insert a number: ");
            scanf(" %i", &n);
            printf("\nft_isascii function return: %d", ft_isascii(n));
            printf("\noriginal function return: %d", isascii(n));
            break;

        case 5:
            printf("\033]0;isprint\007");
            
            printf("Insert a number: ");
            scanf(" %i", &n);
            printf("\nft_isprint function return: %d", ft_isprint(n));
            printf("\noriginal function return: %d", isprint(n));
            break;

        case 6:
            printf("\033]0;strlen\007");
            printf("Insert a string: ");
            scanf(" %s", str);
            printf("\nft_strlen result: %lu", ft_strlen(str));
            printf("\noriginal function result: %lu", strlen(str));
            break;

        case 7:
            printf("\033]0;memset\007");
            printf("\nInsert a string: ");
            scanf(" %s", str);
            printf("\nInsert a char: ");
            scanf(" %c", &c);
            printf("\nInsert the size: ");
            scanf(" %i", &n);

            strcpy(str0, str);
            result_ft = ft_memset(str, c, n);
            result_orig = memset(str0, c, n);

            printf("\nft_memset result: %s", result_ft);
            printf("\noriginal function result: %s", result_orig);
            break;

        case 8:
            printf("\033]0;bzero\007");
            printf("\nInsert a string: ");
            scanf(" %s", str);
            printf("\nInsert the size: ");
            scanf(" %i", &n);
            
            result_ft = str;
            ft_bzero(result_ft, n);
            result_orig = str;
            bzero(result_orig, n);

            printf("\n(its supose to show nothing if size > 0)\nft_bzero result: %s", result_ft);
            printf("\noriginal function result: %s", result_orig);
            break;

        case 9:
            printf("\033]0;memcpy\007");
            printf("Insert a source string: ");
            scanf(" %s", str);
            printf("Insert a destination string: ");
            scanf(" %s", str2);
            printf("Insert the number of bytes to copy: ");
            scanf(" %i", &n);

            strcpy(str0, str2);
            result_ft = ft_memcpy(str2, str, n);
            result_orig = memcpy(str0, str, n);
            
            printf("\nft_memcpy result: %s", result_ft);
            printf("\noriginal function result: %s", result_orig);
            break;
            
        case 10:
            printf("\033]0;memmove\007");
            printf("Insert a source string: ");
            scanf(" %s", str);
            printf("Insert a destination string: ");
            scanf(" %s", str2);
            printf("Insert the number of bytes to move: ");
            scanf(" %i", &n);

            strcpy(str0, str2);
            result_ft = ft_memmove(str2, str, n);
            result_orig = memmove(str0, str, n);
            
            printf("\nft_memmove result: %s", result_ft);
            printf("\noriginal function result: %s", result_orig);

            strcpy(str, "abcdefghi");
            str_p = str;
            str_p += 3;
            result_ft = ft_memmove(str_p, str, 3);

            strcpy(str, "abcdef");
            str_p = str;
            str_p += 3;
            result_orig = memmove(str_p, str, 6);

            printf("\n\n\x1b[34mautomatic test\x1b[0m");
            printf("\n\nsource: abc\x1b[4md\x1b[0mef\ndest: \x1b[4md\x1b[0mef\nsize: 6");

            printf("\n\nft_memmove result: %s", result_ft);
            printf("\noriginal function result: %s", result_orig);
            
            break;

        case 11:
            printf("\033]0;strlcpy\007");
            printf("Insert a source string: ");
            scanf(" %s", str);
            printf("Insert a destination string: ");
            scanf(" %s", str2);
            printf("Insert the size of destination buffer: ");
            scanf(" %i", &n);
            
            strcpy(str0, str2);
            
            printf("\nft_strlcpy result: %zu, %s", ft_strlcpy(str2, str, n), str2);
            printf("\noriginal function result: %zu, %s", strlcpy(str0, str, n), str0);
            break;

        case 12:
            printf("\033]0;strlcat\007");
            printf("Insert a source string: ");
            scanf(" %s", str);
            printf("Insert a destination string: ");
            scanf(" %s", str2);
            printf("Insert the size of destination buffer: ");
            scanf(" %i", &n);
            
            strcpy(str0, str2);
            
            printf("\nft_strlcat result: %zu, %s", ft_strlcat(str2, str, n), str2);
            printf("\noriginal function result: %zu, %s", strlcat(str0, str, n), str0);
            break;
            
#pragma endregion

        #pragma region 13-21

        case 13:
            printf("\033]0;toupper\007");
            printf("Insert a char: ");
            scanf(" %c", &c);
            printf("\nft_toupper result: %c", ft_toupper(c));
            printf("\noriginal function result: %c", toupper(c));
            break;

        case 14:
            printf("\033]0;tolower\007");
            printf("Insert a char: ");
            scanf(" %c", &c);
            printf("\nft_tolower result: %c", ft_tolower(c));
            printf("\noriginal function result: %c", tolower(c));
            break;

        case 15:
            printf("\033]0;strchr\007");
            printf("Insert a string: ");
            scanf(" %s", str);
            printf("Insert a char to find: ");
            scanf(" %c", &c);
            printf("\nft_strchr result: %s", ft_strchr(str, c));
            printf("\noriginal function result: %s", strchr(str, c));
            break;

        case 16:
            printf("\033]0;strrchr\007");
            printf("Insert a string: ");
            scanf(" %s", str);
            printf("Insert a char to find: ");
            scanf(" %c", &c);
            printf("\nft_strrchr result: %s", ft_strrchr(str, c));
            printf("\noriginal function result: %s", strrchr(str, c));
            break;

        case 17:
            printf("\033]0;strncmp\007");
            printf("Insert the first string: ");
            scanf(" %s", str);
            printf("Insert the second string: ");
            scanf(" %s", str2);
            printf("Insert the number of characters to compare: ");
            scanf(" %i", &n);
            printf("\nft_strncmp result: %d", ft_strncmp(str, str2, n));
            printf("\noriginal function result: %d", strncmp(str, str2, n));
            break;

        case 18:
            printf("\033]0;memchr\007");
            printf("Insert a string: ");
            scanf(" %s", str);
            printf("Insert a char to find: ");
            scanf(" %c", &c);
            printf("\nInsert the size: ");
            scanf(" %i", &n);
            
            result_ft = ft_memchr(str, c, n);
            result_orig = memchr(str, c, n);
            printf("\nft_memchr result: %s", result_ft );
            printf("\noriginal function result: %s", result_orig);
            break;

        case 19:
            printf("\033]0;memcmp\007");
            printf("Insert the first string: ");
            scanf(" %s", str);
            printf("Insert the second string: ");
            scanf(" %s", str2);
            printf("Insert the number of characters to compare: ");
            scanf(" %i", &n);
            printf("\nft_memcmp result: %d", ft_memcmp(str, str2, n));
            printf("\noriginal function result: %d", memcmp(str, str2, n));
            break;

        case 20:
            printf("\033]0;strnstr\007");
            printf("Insert the big string: ");
            scanf(" %s", str);
            printf("Insert the small string: ");
            scanf(" %s", str2);
            printf("Insert the number of characters to compare: ");
            scanf(" %i", &n);
            printf("\nft_strnstr result: %s", ft_strnstr(str, str2, n));
            printf("\noriginal function result: %s", strnstr(str, str2, n));
            break;

        case 21:
            printf("\033]0;atoi\007");
            printf("Insert a number (string format): ");
            scanf(" %s", str);
            printf("\nft_atoi result: %d", ft_atoi(str));
            printf("\noriginal function result: %d", atoi(str));
            break;
            
#pragma endregion

        #pragma region 22-23

        case 22:
            printf("\033]0;calloc\007");
            printf("Insert a number of items: ");
            scanf(" %i", &n);
            printf("Insert a size for the items: ");
            scanf(" %i", &n2);

            int *array = (int *)ft_calloc(n, n2);
            int *original_array = (int *)calloc(n, n2);

            if (array == NULL)
            {
                printf("Erro: alocação de memória falhou.\n");
                break;
            }

            for (int i = 0; i < n; i++)
            {
                array[i] = i * 10;
                original_array[i] = i * 10;
            }

            printf("\nft_calloc result: \n");
            for (int i = 0; i < n; i++)
            {
                printf("array[%d] = %d\n", i, array[i]);
            }
            printf("\noriginalfunction result: \n");
            for (int i = 0; i < n; i++)
            {
                printf("array[%d] = %d\n", i, array[i]);
            }
            
            free(array);
            free(original_array);
            break;
            
        case 23:
            printf("\033]0;strdup\007");
            printf("Insert a string: ");
            scanf(" %s", str);
            
            result_ft = ft_strdup(str);
            result_orig = strdup(str);
            printf("\nft_strdup result: %s", result_ft );
            printf("\noriginal function result: %s", result_orig);
            break;
            
#pragma endregion
        
        #pragma region 24-30

        case 24:
            printf("\033]0;substr\007");
            printf("Insert a string: ");
            scanf(" %s", str);
            printf("Insert whre you want the string to start: ");
            scanf(" %d", &n);
            printf("Insert max size of the new string: ");
            scanf(" %d", &n2);
            printf("\nft_substr result: %s", ft_substr(str, n, n2));
            break;

        case 25:
            printf("\033]0;ft_strjoin\007");
            printf("Insert the first strings: ");
            scanf(" %s", str);
            printf("Insert the second strings: ");
            scanf(" %s", str2);
            printf("\nft_strjoin result: %s", ft_strjoin(str, str2));
            break;

        #pragma endregion
        
        default:
            printf("\033[31mInvalid number\033[0m \n");
            return 0;
            break;
    }
    

    printf("\n\nYou want to try this function again? \033[32m(y/n)\033[0m\n");
    
    scanf(" %c", &c);
    if(c == 'y')
    {
        system("clear");
        testar(i);
    }
    system("clear");

    return 0;
}

void ABC(unsigned int index, char *c) 
{
    (void)index;
    if (*c >= 'a' && *c <= 'z') {
        *c -= 32;
    }
}
int main()
{
    char i = 0;
    while(i != 'q')
    {
        printf("\033]0;Test Menu\007");
        
        printf(
            "\nType:\n"
            "\n\x1b[32m t\x1b[0m to test a function"
            "\n\033[34m n\x1b[0m to show norminette errors"
            "\n\033[35m f\x1b[0m to execute 42formatter"
            "\n\033[96m s\x1b[0m to execute a single test"
            "\n\033[93m b\x1b[0m to execute the best test"
            "\n\033[38;5;208m r\x1b[0m to reload the project"
            "\n\x1b[33m ?\x1b[0m to see the functions list"
            "\n\x1b[31m q\x1b[0m to quit"
            "\n\n> "
        );
        scanf(" %c", &i);
        system("clear");
        if (i == '?')
        {
            char c = 0;
            while (c != 'q')
            {
                printf("\n1- isalpha");
                printf("\n2- isdigit");
                printf("\n3- isalnum");
                printf("\n4- isascii");
                printf("\n5- isprint");
                printf("\n6- strlen");
                printf("\n7- memset");
                printf("\n8- bzero");
                printf("\n9- memcpy");
                printf("\n10- memmove");
                printf("\n11- strlcpy");
                printf("\n12- strlcat");
                printf("\n13- toupper");
                printf("\n14- tolower");
                printf("\n15- strchr");
                printf("\n16- strrchr");
                printf("\n17- strncmp");
                printf("\n18- memchr");
                printf("\n19- memcmp");
                printf("\n20- strnstr");
                printf("\n21- atoi");
                printf("\n22- calloc");
                printf("\n23- strdup");
                
                printf("\n\nPress \x1b[31mq\x1b[0m to quit\n");
                scanf(" %c", &c);
                system("clear");
            }
        }
        else if (i == 't')
        {
            int i;
            int q = 0;
            while (!q)
            {
                printf("Insert a\x1b[32m function number\033[0m to test it or\x1b[31m 0\033[0m to quit: ");
                scanf(" %i", &i);
                system("clear");

                q = testar(i);
            }
            
        }
        else if (i == 'n')
        {
            system("clear");
            printf("\033[34mnorminette test (only errors): \033[0m\n");
            system("norminette ft_*.c *.h 2>&1 | grep -E \"Error|Warning\"");
        }
        else if (i == 'f')
        {
            system("clear");
            printf("\033[35mnorminette formatter \033[0m\n");
            system("python3 -m c_formatter_42 ft_*.c *.h");
        }
        else if (i == 'r')
        {
            system("clear");
            printf("\033[35mreload project... \033[0m\n");
            system("clear && cc *.c *.h -Wall -Wextra -Werror -lbsd && ./a.out");
        }
        else if (i == 'b')
        {
            printf(
                "\n\t    ⢀⣠⠤⡶⣲⢺⣴⣶⢭⣉⢲⣀⠀⠀⠀⠀⠀⠀⠀⠀   \t    ⠀⠀⠀⣠⡤⠒⠂⢀⣈⣉⠉⠑⠒⠢⠤⡀⠀⠀⠀⠀⠀⠀⠀"
                "\n\t  ⢀⡾⢵⣶⣿⣿⣿⣾⣷⣳⣿⣷⣵⣈⠷⢤⡀⠀⠀⠀⠀⠀   \t    ⠀⡰⠉⢁⣰⣶⣾⣿⣿⣿⣿⣷⣶⣼⣶⣼⣆⠀⠀⠀⠀⠀⠀"
                "\n\t  ⠘⢾⣿⡿⠿⠿⠿⠿⠿⠿⢿⡿⣿⣿⣿⣾⣾⣦⠀⠀⠀⠀   \t   ⢠⣁⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣄⡀⠀⠀⠀"
                "\n\t  ⣠⡋⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠻⢿⢿⣧⠀⠀⠀   \t   ⣿⣿⣿⣿⣿⣿⠛⠉⠉⠁ ⠈⠉⠉⠙⠻⣿⣿⣷⣿⡄"
                "\n\t ⣰⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣳⢮⣧⠀⠀   \t   ⣿⣿⡿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣿⣷⣿⢱"
                "\n\t⢠⣧⠇⡠⠄⣤⣤⣄⡀ ⠀⣀⣤⣄⣤⣀⠀⠀⣿⣿⣿⣯⣇⠀   \t   ⣿⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣿⣟⠂⡇"
                "\n\t⠈⣿ ⢀⣶⣾⣿⣿⠁⠀⢸⣿⣿⣿⣧⣌⣥⠀⠘⣿⣿⣿⣿⠀   \t   ⣿⣿⠀⢀⣤⣶⣶⣦⠀⠀⢠⣴⣿⣷⣶⡄⠀⠘⢿⣿⣧⡇"
                "\n\t⢀⣿ ⠈⠁⠀⠀⠁⠀⠀⠀⠉⠉⠭⠽⠿⠻⠁⠀⣿⣿⣿⡏⠀   \t  ⢸⣿⡏ ⠠⡶⢽⡶⠿⠃⠀⠘⢿⠿⠶⠟⠿⠂⠀⢸⣿⣿⡿⡀"
                "\n\t⡏⠆ ⠀⠀⠀⠀⠀⡀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠸⠟⢋⣿⣆   \t  ⡜⢿⣿ ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠟⠋⠀⡇"
                "\n\t⡎  ⢀⡴⠂⠈⠉⠻⠿⠿⠛⣀⢲⣤⣄⣀⠀⠀⠈⠘⣏⢹⡿   \t  ⢱⠈⠙ ⠀⠀⠀⣠⢠⣤⣤⣤⣤⣤⡤⡀⠀⠀⠀⠀⠀⣤⠀⢰"
                "\n\t⠱⡄⠘⢻⣳⣤⡶⠖⠒⠶⠶⢶⣿⣷⣿⣿⣿⣟ ⠀⠄⠠⣰⠃   \t  ⢸ ⢢⡄⠀⠀⠴⣧⣴⡶⢿⢿⣿⣿⣿⣾⣦⠀⡀⢠⣆⠀⠙⠸"
                "\n\t ⢹⠀⠀⠀⠈⠓⠒⠒⠒⠒⠒⠛⠁⢨⣼⣿⣿⡀⣼⠖⠛⠁⠀   \t  ⢠ ⠈⣷⣀⡀⠨⣿⢿⢋⣉⣉⣉⣙⡿⣿⡿⣠⣟⣾⡿⣤⡠⠂"
                "\n\t ⠘⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣿⣿⣿⣿⢁⠀⠀⠀⠀⠀   \t  ⠘⠦⠤⣿⣿⣷⣼⣿ ⠉⠉⠉⠉⠉⠀⢸⣿⣿⣿⣿⣿⠁⠀⠀"
                "\n\t ⠀⢸⠀⠀⠀⢀⣀⣀⣀⣠⣤⣶⣿⣿⣿⡿⣁⡎⢸⠀⠀     \t    ⠀⠀⢸⢻⣿⣿⣿⣶⡀⠾⣦⣷⠔⢧⣾⣿⣿⣿⣿⢸⠀⠀⠀"
                "\n\t ⠀⢸⠀⠀⠀⠘⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠁⠸⠀      \t    ⠀⢀⣾⠀⠉⣿⣿⣿⣧⣦⣻⣳⣶⣿⣿⣿⣾⣿⡿⢸⠀⠀⠀"
                "\n\t ⠀⢸⠀⠀⠀⠀⠀⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡄⡇      \t    ⢀⣿⣿⡀⠈⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠁⢸⣧"
                "\n\t ⢀⣼⠀⠀⠀⠀⠀⠈⢹⣿⣿⣿⡟⣿⣿⣿⣟⡁⠀⢿⣷⡄⠀   \t   ⠈⢿⣿⣿⡄⠀⠀⠀⠉⠛⠛⠛⠛⠉⠁⠀⠀⠀⠀⣿⣿⣇⠀"
                "\n\t ⣸⣿⠀⠀⠀⠀⠀⠀⠸⣿⣿⣿⣿⣝⣿⣿⡍⠁⠀⢸⣿⣷⠀   \t   ⠀⢸⣿⣿⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⣿⣿⣿⠀"
                "\n\t ⣿⣿⡀⠀⠀⠀⠀⠀⢐⣿⣿⣿⣿⣿⣿⣯⠁⠀⠀⢸⣿⣿⠀   \t     ⣿⣿⣿⣿⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⣿⣿⣿⡇⠀"
                "\n\t ⢿⢿⣿⣄⠀⠀⠀⠀⢼⣿⣿⣿⣿⣿⣿⡯⠀⢠⢒⣿⣿⡏⠀   \t     ⠘⢿⣿⣿⣿⣧⡀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⠟⠁"
                "\n\t ⠈⢮⡻⣿⣷⣀⠀⢀⢸⣿⣿⣟⣿⣿⠿⠒⣀⣤⣿⣿⠏⠀⠀   \t       ⠙⠿⢿⣿⣿⣶⣄⡀⠀⠀⠀⠀⣰⣿⣿⠋"
                "\n\t ⠀⠀⠙⠺⣿⣿⣿⣾⣾⣿⣭⣭⣭⣷⣾⣿⣿⣿⠟⠁⠀⠀    \t  ⠀⠀⠀⠀⠀⠀⠀⠀⠙⢿⣿⣿⣦⠀⠀⠀⣿⣿⠃⠀⠀⠀⠀"
                "\n\t ⠀⠀⠀⠀⠀⠉⠛⠻⠿⠿⠿⠿⠿⠿⠟⠛⠉⠁⠀⠀⠀     \t  ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⣿⣿⣷⣤⣺⣿⡇⠀⠀⠀⠀⠀"
                "\n\t                                       ⠀⠀⠀⠀⠀⠀⠈⠛⠿⣿⠿⠋⠀⠀⠀⠀⠀ "
                "\n"
                "\n\t           RONALDO                             MESSI"
            );
            printf("\n\ntype r for Ronaldo or m for Messi\n> ");
            while (i != 'r' || i != 'm')
            {
                scanf(" %c", &i);
                if (i == 'r')
                {
                    system("clear");
                    printf("SSSSS");
                    for (int i = 0; 1; i++)
                        printf("I");
                    printf("M");
                    break;
                }
                else if (i == 'm')
                {
                    system("clear");
                    printf("you dont deserve this program");
                    exit(0);
                }
            }
            
                
            
        }
        else if (i == 'q')
        {
            system("clear");
            exit(0);
        }
        else if (i == 's')
        {
            t_list *l = ((void*)0);
            t_list *n = ft_lstnew(strdup("OK"));
        
            ft_lstadd_back(&l, n);

            printf("\n -> %s", (char *)l->content);

            
            // char **tab = ft_split("hola mundo como estas", ' ');
            // for(int i = 0; i < 5; i++)
            // {
            //     printf("\n%d: %s",i,tab[i]);
            // }
            
            // printf(
            //     "\noriginal: %s"
            //     "\nmine: %s"
            //     "\nteste result: "
            //     ,i1,i2
            //     );
                
            // if (i1 == i2)
            //     printf("success \n\n");
            // else
            //     printf("failed \n\n");
            printf("\n\n");

        }
    }
}

/* 

"\n\033[38;5;208m f\x1b[0m to open francinette menu"
else if (i == 'f')
{
    system("clear");
    printf("\033]0;Francinette Menu\007");
    printf(
        "\033[38;5;208mfrancinette menu \033[0m"
        "\ntype the name of the function that you want to chek or \"all\" to execute eveything"
        "\n\n> "
    );
    scanf(" %s", str);
    if(strcmp(str, "all"))
        system("~/francinette/tester.sh");
    else
        system(ft_strjoin("~/francinette/tester.sh", str));
    
} */

