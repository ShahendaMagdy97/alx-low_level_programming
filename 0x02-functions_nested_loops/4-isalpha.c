#include "main.h"

/**
 * _isalpha - checkss for alphabetic character
 * @c: the characteer to be checkedd
 * Return: 1 if c is a letter, 0 otherwises
 */
int _isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
