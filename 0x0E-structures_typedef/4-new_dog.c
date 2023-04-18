#include <stdlib.h>
#include "dog.h"

/**
 * _strlen - a function that gets length of string
 *
 * @str: the string to get lenght
 *
 * Return: length of @str
*/

int _strlen(const char *str)
{
	int L = 0;

	while (*str++)
		L++;
	return (L);
}

/**
 * _strcopy - a function that returns @dest with a copy of a string from @src
 *
 * @src: string to copy
 * @dest: copy string to here
 *
 * Return: @dest
*/

char *_strcopy(char *dest, char *src)
{
	int c;

	for (c = 0; src[c]; c++)
		dest[c] = src[c];
	dest[c] = '\0';

	return (dest);
}

/**
 * new_dog - a function that creates a new dog
 *
 * @name: name of the dog
 * @age: age of the dog
 * @owner: dog owner
 *
 * Return: struct pointer dog
 *	NULL if the function fails
*/

dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog;

	/*if name and owner are empty and age is less than zero return null*/
	if (!name || age < 0 || !owner)
		return (NULL);

	dog = (dog_t *) malloc(sizeof(dog_t));
	if (dog == NULL)
		return (NULL);

	dog->name = malloc(sizeof(char) * (_strlen(name) + 1));
	if ((*dog).name == NULL)
	{
		free(dog);
		return (NULL);
	}

	dog->owner = malloc(sizeof(char) * (_strlen(owner) + 1));
	if ((*dog).owner == NULL)
	{
		free(dog->name);
		free(dog);
		return (NULL);
	}

	dog->name = _strcopy(dog->name, name);
	dog->age = age;
	dog->owner = _strcopy(dog->owner, owner);

	return (dog);
}
