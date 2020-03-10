##
## EPITECH PROJECT, 2019
## CPE_getnextline_2019
## File description:
## Makefile
##

SRC = get_next_line.c

OBJ = tests/getnextline_test.c

tests_run	:
	gcc -o units $(SRC) $(OBJ) -lcriterion --coverage
	./units

clean	:
	rm -f *.gcda
	rm -f *.gcno

fclean	: clean
	rm -f units

get_html :	tests_run
	gcovr --branches --exclude bonus --exclude tests --html --html-details -o rapport_branches.html