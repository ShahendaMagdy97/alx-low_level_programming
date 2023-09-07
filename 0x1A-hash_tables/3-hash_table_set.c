#include "hash_tables.h"

/**
 * hash_table_set - Add or update an element in a hash table.
 * @ht: A pointer to the hash table.
 * @key: The key to add - cannot be an empty string.
 * @value: The value associated with key.
 *
 * Return: Upon failure - 0.
 *         Otherwise - 1.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
hash_node_t *neww;
char *value_copyed;
unsigned long int index, x;

if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
return (0);

value_copyed = strdup(value);
if (value_copyed == NULL)
return (0);

index = key_index((const unsigned char *)key, ht->size);
for (x = index; ht->array[x]; x++)
{
if (strcmp(ht->array[x]->key, key) == 0)
{
free(ht->array[x]->value);
ht->array[x]->value = value_copyed;
return (1);
}
}

neww = malloc(sizeof(hash_node_t));
if (neww == NULL)
{
free(value_copyed);
return (0);
}
neww->key = strdup(key);
if (neww->key == NULL)
{
free(neww);
return (0);
}
neww->value = value_copyed;
neww->next = ht->array[index];
ht->array[index] = neww;

return (1);
}
