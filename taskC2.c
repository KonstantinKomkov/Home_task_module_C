#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 255

typedef struct
{
	int items[MAX_SIZE];
	int top;
} Stack;

void initStack(Stack* s)
{
	s->top = -1;
}

int isFull(Stack* s)
{
	return s->top == MAX_SIZE - 1;
}

int isEmpty(Stack* s)
{
	return s->top == -1;
}

void push(Stack* s, int item)
{
	if (!isFull(s))
	{
		s->items[++(s->top)] = item;
	}
}

int pop(Stack* s)
{
	if (!isEmpty(s))
	{
		return s->items[(s->top)--];
	}
	return -1; // Возвращаем -1, если стек пуст (ошибка)
}

int evaluate_RPN(char* tokens)
{
	Stack stack;
	initStack(&stack);

	char* token = strtok(tokens, " ");

	while (token != NULL)
	{
		if (isdigit(token[0])) // Если это число
		{ 
		    push(&stack, atoi(token));
		} 
		else // Если это оператор
		{ 
			int b = pop(&stack);
			int a = pop(&stack);
			int result = 0;

			switch (token[0])
			{
				case '+':
					result = a + b;
					break;
				case '-':
					result = a - b;
					break;
				case '*':
					result = a * b;
					break;
				case '/':
					result = a / b;
					break;
			}

			push(&stack, result);
		}
		token = strtok(NULL, " ");
	}
	return pop(&stack); // Возвращаем результат
}

int main()
{
	char input[MAX_SIZE];
	int i = 0;

	while((input[i] = getchar()) != '\n')
	{
		i++;
	}

	int result = evaluate_RPN(input);
	printf("%d\n", result);

	return 0;
}
