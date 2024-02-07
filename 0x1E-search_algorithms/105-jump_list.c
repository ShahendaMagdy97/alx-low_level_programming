#include "search_algos.h"
#include <math.h>

/**
 * jump_list - searches a list of values for a value
 * utilizing the Jump search method, integers
 *
 * @list: input list
 * @size:dimension of the array
 * @value: a good place to look
 * Return: the number's index
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
size_t index, t, n;
listint_t *drev;

if (list == NULL || size == 0)
return (NULL);

n = (size_t)sqrt((double)size);
index = 0;
t = 0;

do {
drev = list;
t++;
index = t *n;

while (list->next && list->index < index)
list = list->next;
if (list->next == NULL && index != list->index)
index = list->index;
printf("Value checked at index [%d] = [%d]\n", (int)index, list->n);
} while (index < size && list->next && list->n < value);
printf("Value found between indexes ");
printf("[%d] and [%d]\n", (int)drev->index, (int)list->index);
while (drev && drev->index <= list->index)
{
printf("Value checked at index [%d] = [%d]\n",
(int)drev->index, drev->n);
if (drev->n == value)
return (drev);
drev = drev->next;
}

return (NULL);
}
