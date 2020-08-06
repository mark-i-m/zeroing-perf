
FLAGS=-O3 -march=native

COMMON_H=memset-test.h
COMMON_C=memset-test.c

all: naive erms

naive: memset-naive.c $(COMMON_C) $(COMMON_H)
	gcc $(FLAGS) -o $@ $< $(COMMON_C)

erms: memset-ermsb.c  $(COMMON_C) $(COMMON_H)
	gcc $(FLAGS) -o $@ $< $(COMMON_C)

clean:
	rm -f naive erms
