#include <stdio.h>

#define MAX_NUMBERS 100

int is_three_digit_number(int num)
{
	return num >= 100 && num <= 999;
}

void generate_three_digit_numbers(char *numbers, int length, int index, int current_num, int counter, int *unique_numbers) 
{
	if (counter == 3)
	{
		if (is_three_digit_number(current_num))
		{
			unique_numbers[current_num] = 1;
		}
		return;
	}
	for (int i = index; i < length; i++)
	{
		generate_three_digit_numbers(numbers, length, i + 1, current_num * 10 + (numbers[i] - '0'), counter + 1, unique_numbers);
	}
}

int main()
{
	int i = 0;
	char N[MAX_NUMBERS];

	while((N[i] = getchar()) != '\n')
	{
		i++;
	}

	int unique_numbers[1000] = {0};

	generate_three_digit_numbers(N, i, 0, 0, 0, unique_numbers);

	int counter = 0;
	for (int i = 100; i < 1000; i++) 
	{
		if (unique_numbers[i]) 
		{
			counter++;
		}
	}
	printf("%d\n", counter);
	return 0;
}
