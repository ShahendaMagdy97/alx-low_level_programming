#include "hash_tables.h"

shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);

/**
 * shash_table_create - Creates a sorted hash table.
 * @size: The size of neww sorted hash table.
 *
 * Return: If an error occurs - NULL.
 *         Otherwise - a pointer to the neww sorted hash table.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
shash_table_t *ht;
unsigned long int x;

ht = malloc(sizeof(shash_table_t));
if (ht == NULL)
return (NULL);

ht->size = size;
ht->array = malloc(sizeof(shash_node_t *) * size);
if (ht->array == NULL)
return (NULL);
for (x = 0; x < size; x++)
ht->array[x] = NULL;
ht->shead = NULL;
ht->stail = NULL;

return (ht);
}

/**
 * shash_table_set - Adds an element to a sorted hash table.
 * @ht: A pointer to the sorted hash table.
 * @key: The key to add - cannot be an empty string.
 * @value: The value associated with key.
 *
 * Return: Upon failure - 0.
 *         Otherwise - 1.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
shash_node_t *neww, *tmp;
char *value_copyed;
unsigned long int index;

if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
return (0);

value_copyed = strdup(value);
if (value_copyed == NULL)
return (0);

index = key_index((const unsigned char *)key, ht->size);
tmp = ht->shead;
while (tmp)
{
if (strcmp(tmp->key, key) == 0)
{
free(tmp->value);
tmp->value = value_copyed;
return (1);
}
tmp = tmp->snext;
}

neww = malloc(sizeof(shash_node_t));
if (neww == NULL)
{
free(value_copyed);
return (0);
}
neww->key = strdup(key);
if (neww->key == NULL)
{
free(value_copyed);
free(neww);
return (0);
}
neww->value = value_copyed;
neww->next = ht->array[index];
ht->array[index] = neww;

if (ht->shead == NULL)
{
neww->sprev = NULL;
neww->snext = NULL;
ht->shead = neww;
ht->stail = neww;
}
else if (strcmp(ht->shead->key, key) > 0)
{
neww->sprev = NULL;
neww->snext = ht->shead;
ht->shead->sprev = neww;
ht->shead = neww;
}
else
{
tmp = ht->shead;
while (tmp->snext != NULL && strcmp(tmp->snext->key, key) < 0)
tmp = tmp->snext;
neww->sprev = tmp;
neww->snext = tmp->snext;
if (tmp->snext == NULL)
ht->stail = neww;
else
tmp->snext->sprev = neww;
tmp->snext = neww;
}

return (1);
}

/**
 * shash_table_get - Retrieve the value associated with
 *                   a key in a sorted hash table.
 * @ht: A pointer to the sorted hash table.
 * @key: The key to get the value of.
 *
 * Return: If the key cannot be matched - NULL.
 *         Otherwise - the value associated with key in ht.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
shash_node_t *node;
unsigned long int index;

if (ht == NULL || key == NULL || *key == '\0')
return (NULL);

index = key_index((const unsigned char *)key, ht->size);
if (index >= ht->size)
return (NULL);

node = ht->shead;
while (node != NULL && strcmp(node->key, key) != 0)
node = node->snext;

return ((node == NULL) ? NULL : node->value);
}

/**
 * shash_table_print - Prints a sorted hash table in order.
 * @ht: A pointer to the sorted hash table.
 */
void shash_table_print(const shash_table_t *ht)
{
shash_node_t *node;

if (ht == NULL)
return;

node = ht->shead;
printf("{");
while (node != NULL)
{
printf("'%s': '%s'", node->key, node->value);
node = node->snext;
if (node != NULL)
printf(", ");
}
printf("}\n");
}

/**
 * shash_table_print_rev - Prints a sorted hash table in reverse order.
 * @ht: A pointer to the sorted hash table to print.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
shash_node_t *node;

if (ht == NULL)
return;

node = ht->stail;
printf("{");
while (node != NULL)
{
printf("'%s': '%s'", node->key, node->value);
node = node->sprev;
if (node != NULL)
printf(", ");
}
printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table.
 * @ht: A pointer to the sorted hash table.
 */
void shash_table_delete(shash_table_t *ht)
{
shash_table_t *head = ht;
shash_node_t *node, *tmp;

if (ht == NULL)
return;

node = ht->shead;
while (node)
{
tmp = node->snext;
free(node->key);
free(node->value);
free(node);
node = tmp;
}

free(head->array);
free(head);
}
