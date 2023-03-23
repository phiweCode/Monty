#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>

int main ()
{
stack_t *stack;
stack_t *temp;

temp = NULL;
stack = NULL;

push_stack(&stack,1);
push_stack(&stack,4);
push_stack(&stack,5);
push_stack(&stack,9);
push_stack(&stack,8);

temp = stack;

display_stack(&temp);

return 0;
}