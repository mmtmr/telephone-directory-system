#include "struct.h"
#include "function.h"

void countLineAndReadTxt(int* lineCount)
{
	char charKey;
	FILE* tel = fopen("tel.txt", "r");
	if (tel == NULL)
	{
		printf("Creating tel.txt in the program's directory.\n");
		tel = fopen("tel.txt", "w");
		{
			if (tel == NULL)
			{
				printf("Cannot create file. The program will end.\n");
				exit(1);
			}
		}
		fclose(tel);
		tel = fopen("tel.txt", "r");
		printf("Success in creating tel.txt\n");
		return;
	}
	
	while (!feof(tel))
	{
		charKey = fgetc(tel);
		if (charKey == '\n')
		{
			*lineCount+=1;
		}
			
	}
	fclose(tel);
	return;
}