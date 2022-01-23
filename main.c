#include "struct.h"
#include "function.h"
int main()
{
	
	int* lineCount=0, sizeStruct = sizeof(struct apuStaff) + 14;
	struct apuStaff* table;
	countLineAndReadTxt(&lineCount);
	table= malloc(sizeStruct * 999);

	txtToStruct(table,&lineCount);
	while (lineCount == 0)
	{
		printf("The file is empty. Please key in at least one employee details to proceed.\n");
		addStaff(table, &lineCount);
	}
	while (lineCount!=0)
	{
		mainMenu(&lineCount, table);
	}
	
	
	free(table);
	return 0;
}
