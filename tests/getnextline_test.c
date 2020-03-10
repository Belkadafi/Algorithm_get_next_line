/*
** EPITECH PROJECT, 2019
** CPE_getnextline_2019
** File description:
** getnextline_test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../get_next_line.h"

char *get_next_line(int fd);

Test(get_next_line, Should_return_first_line)
{
    int fd = open("bonus/getnextline_test.txt", O_RDONLY);

    cr_assert_str_eq(get_next_line(fd), "XXXXXXXXXXXXXXXXXXXXXX\
XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXK0Okxddlc;,,'''.\
''''''''''''''''',,;cldxO0KXKKKXXXXXXKKKXKKKKKKKKKKKKKKKKKKKKKKK\
KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK0000000000000000000");
}

Test(get_next_line, Should_handle_no_open)
{
    int fd = -1;

    cr_assert_eq(get_next_line(fd), NULL);
}

Test(get_next_line, Should_a_lot_of_calls)
{
    int fd = open("bonus/getnextline_test2.txt", O_RDONLY);

    for (int i = 0; i < 15; i += 1)
        get_next_line(fd);
    cr_assert_eq(get_next_line(fd), NULL);
}

Test(get_next_line, Should_handle_directory_open)
{
    int fd = open("bonus", O_RDONLY);

    cr_assert_eq(get_next_line(fd), NULL);
}