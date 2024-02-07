#include "search_algos.h"

/**
 * linear_skip - examines a skip list in search of a value
 * @list: entry list
 * @value: a good place to look
 * Return: the number's index
 */
skiplist_t *linear_skip(skiplist_t *list,
int value)
{
skiplist_t *wgo;

if (list == NULL)
return (NULL);

wgo = list;

do {
list = wgo;
wgo = wgo->express;
printf("Value checked at index ");
printf("[%d] = [%d]\n", (int)wgo->index, wgo->n);
} while (wgo->express && wgo->n < value);

if (wgo->express == NULL)
{
list = wgo;
while (wgo->next)
wgo = wgo->next;
}

printf("Value found between indexes ");
printf("[%d] and [%d]\n", (int)list->index,
(int)wgo->index);

for (; list != wgo->next; list = list->next)
{
printf("Value checked at index [%d] = [%d]\n",
(int)list->index, list->n);
if (list->n == value)
return (list);
}

return (NULL);

}
