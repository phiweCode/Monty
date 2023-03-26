#include "monty.h"
#define MAX_LINE_LENGTH 256

int main(int argc,char *argv[])
{

stack_t *stack;
char line[MAX_LINE_LENGTH];
char *opcode = malloc(sizeof(char) * MAX_LINE_LENGTH);
long unsigned int idx;
unsigned int data;
int digit_allc = -1;
unsigned int line_number = 1;

FILE *file = fopen(argv[1], "r");

if (!file)
{
fprintf(stderr, "Failed to open file.\n");
exit(EXIT_FAILURE);
}

while(fgets(line, MAX_LINE_LENGTH, file))
{

printf("%s\n", line);

for (idx = 0; line[idx] != '$'; idx ++)
{
    if (isalpha(line[idx]))
    {
      printf("%c\n", line[idx]);
      opcode[idx] += line[idx];
    }
    else if (isdigit(line[idx]))
    {
    data = atoi(&line[idx]);
    digit_allc = 1;
    }
}

printf("%s", line);
printf("instruction read is %s and the input is %d \n\n", opcode, argc);

printf("instruction %s\n", instruction_set[0].opcode);
printf("instruction set size %lu\n", sizeof(instruction_set));

for (idx = 0; idx < sizeof(instruction_set)/sizeof(instruction_set[0]); idx++)
{
printf("idx = %lu, opcode = %s, fopcode = %s,\n", idx, opcode, instruction_set[idx].opcode);

if(strcmp(opcode,instruction_set[idx].opcode) == 0)
{

printf("instruction matched\n");

if(digit_allc == 1)
{
push(&stack, data);
digit_allc = -1;
}
opcode = NULL;
break;

}

}
opcode = malloc(sizeof(char) * MAX_LINE_LENGTH);
line_number++;
}

pall(&stack, line_number);
return (0);
}