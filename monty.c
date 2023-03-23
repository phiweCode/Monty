#include "monty.h"
#define LIMIT 100

stack_t *push_stack(stack_t **stack, int data)
{
    stack_t *new_stack = malloc(sizeof(stack_t));
    stack_t *temp_stack = malloc(sizeof(stack_t));

    if (new_stack == NULL)
    {
    return (NULL);
    }

    new_stack->n = data;
    new_stack->next = NULL;
    new_stack->prev = NULL;

    if (*stack == NULL)
    {
    *stack = new_stack;
    return (new_stack);
    }

    temp_stack = *stack;

    while(temp_stack->next != NULL )
    {
    temp_stack = temp_stack->next;
    }

    temp_stack->next = new_stack;
    new_stack->next = NULL;

    return new_stack;
}

void display_stack(stack_t **stack)
{

stack_t *temp = malloc(sizeof(stack_t));
int contents[LIMIT];
int idx;
int i;
idx = 0;


if (*stack == NULL)
{
printf("stack underflow\n");
}
else
{
temp = *stack;

while(temp->next != NULL)
{
contents[idx] = temp->n;
temp = temp->next;
idx++;
}

contents[idx] = temp->n;

for (i = idx ; i >= 0; i--)
{
printf("[%d]\n", contents[i]);
}

}

}

/**
 * opcode_handler- handles the opcode instruction
 * @stack: pointer to the stack
 * @line_number: line of the opcode instruction
*/

instruction_t instruction_set[] =
{
 {"push", push_stack},
 {"pall", display_stack}
};

