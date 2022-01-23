#include "struct.h"
#include "function.h"

void preventBlankInput(char* input)
{
	if (*input == "")
	{
		printf("Input Error. Please enter again:\n");
		gets(*input);
	}

}