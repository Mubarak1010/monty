#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

stack_t *top = NULL;

void pall(void)
{
	stack_t *traverse;

	if (top == NULL)
	{
		return;
	}
	traverse = top;
	while (traverse != NULL)
	{
		printf("%d ", traverse->n);
		traverse = traverse->next;
	}
	printf("\n");
}

void push(int value_of_node)
{
	stack_t *new_node;

	new_node = (stack_t *)malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		return;
	}
	new_node->n = value_of_node;
	new_node->prev = NULL;
	new_node->next = top;
	if (top != NULL)
	{
		top->prev = new_node;
	}
	top = new_node;
	printf("%d\n", value_of_node);
}

int main(int argc, char *argv[])
{
	stack_t *temporary;
	int value_of_node;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <int>\n", argv[0]);
		fprintf(stderr, "Error: No argument or too many arguments provided\n");
		return (EXIT_FAILURE);
	}

	value_of_node = atoi(argv[1]);
	if (value_of_node == 0 && *argv[1] != '0')
	{
		fprintf(stderr, "Error: %s: usage: push integer\n", argv[0]);
		return (EXIT_FAILURE);
	}
	push(value_of_node);
	while (top != NULL)
	{
		temporary = top;
		top = top->next;
		free(temporary);
	}
	return (EXIT_SUCCESS);
}
