#include <stdio.h>
#include <string.h>

int main()
{
	char str1[2000], str2[2000];

	fgets(str1, sizeof(str1), stdin);
	fgets(str2, sizeof(str2), stdin);

	str1[strcspn(str1, "\n")] = 0; // Удаляем символы новой строки, если они есть
	str2[strcspn(str2, "\n")] = 0; // Удаляем символы новой строки, если они есть

	int len1 = strlen(str1);
	int len2 = strlen(str2);

	int maxPrefixSuffix = 0;
	for (int i = 1; i <= len1 && i <= len2; i++)
	{
		if (strncmp(str1, str2 + len2 - i, i) == 0)
		{
			maxPrefixSuffix = i;
		}
	}

	int maxSuffixPrefix = 0;
	for (int i = 1; i <= len1 && i <= len2; i++)
	{
		if (strncmp(str1 + len1 - i, str2, i) == 0)
		{
			maxSuffixPrefix = i;
		}
	}

	printf("%d %d\n", maxPrefixSuffix, maxSuffixPrefix);

	return 0;
}
