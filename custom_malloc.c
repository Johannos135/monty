#include "monty.h"
/**
 * _calloc - concatenates allocated string
 * @vch_v: number of elements
 * @size: type of elements
 */
void *_calloc(unsigned int vch_v, unsigned int size)
{
	void *p = NULL;
	unsigned int i;

	if (vch_v == 0 || size == 0)
	{
		return (NULL);
	}
	p = malloc(vch_v * size);
	if (p == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < (vch_v * size); i++)
	{
		*((char *)(p) + i) = 0;
	}
	return (p);
}
/**
 * _realloc - reallocate the memory
 * @ptr: malloc pointer to reallocate
 * @old_size: old number of bytes
 * @new_size: new number of Bytes
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p = NULL;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
	{
		p = malloc(new_size);
		if (!p)
			return (NULL);
		return (p);
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size > old_size)
	{
		p = malloc(new_size);
		if (!p)
			return (NULL);
		for (i = 0; i < old_size; i++)
			p[i] = *((char *)ptr + i);
		free(ptr);
	}
	else
	{
		p = malloc(new_size);
		if (!p)
			return (NULL);
		for (i = 0; i < new_size; i++)
			p[i] = *((char *)ptr + i);
		free(ptr);
	}
	return (p);
}
