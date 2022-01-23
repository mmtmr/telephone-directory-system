#include "struct.h"
#include "function.h"
void correctInput(char *input, int need)
{
	int i;
	if (strcspn(input, "\n")==0)
	{
		
		(input)[0] = '-';
		(input)[1] = '\0';
	}
	else (input)[strcspn(input, "\n")] = '\0';

	for (i = 0; input[i] != '\0'; i++)//convert to uppercase
	{
		if (input[i] >= 'a' && input[i] <= 'z')
		{
			input[i] = input[i] - 32;
		}
	}

	if (input[0] == '-'&&need>0)
	{
		printf("Input cannot leave blank!\n");
		printf("Enter again:");
		fgets(input, need, stdin);
		correctInput(input, need);
	}

	return;

}

char verifyDetails(char* key)
{
	if (key[0] == '-')
	{
		return 'F';
	}
		
	else
		return 'T';
}