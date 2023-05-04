#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <limits.h>

int _putchar(char c);
unsigned int binary_to_uint(const char *b);
void print_binary(unsigned long int p);
int get_bit(unsigned long int i, unsigned int index);
int set_bit(unsigned long int *i, unsigned int index);
int clear_bit(unsigned long int *i, unsigned int index);
unsigned int flip_bits(unsigned long int x, unsigned long int y);
int get_endianness(void);

#endif
