cc := gcc -Wall -Wextra -Werror -std=c11
accompaniment := str_math/*.c helpers/*.c decimal/*.c
files := s21_decimal.c $(accompaniment)

all: $(files)
	$(cc) $(files) -o s21_decimal
	./s21_decimal

hui:
	gcc -w $(files)
	./a.out

test:
	$(cc) $(accompaniment) tests/*.c -lcheck -lsubunit -lm -o test.out
	./test.out

clean:
	rm a.out s21_decimal test.out