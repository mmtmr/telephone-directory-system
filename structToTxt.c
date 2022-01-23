#include "struct.h"
#include "function.h"

void structToTxt(struct apuStaff* table,int* lineCount)
{
	int i = 0, sizeStruct = sizeof(struct apuStaff) + 14;
	FILE* tel = fopen("tel.txt", "w");

	sortDepartment(table, lineCount);
	if (tel == NULL)
	{
		printf("Error opening tel.txt. Program terminating...\n");
		exit(1);
	}
	printf("Writing...\n");

	while (i!= *lineCount)
	{
		//below code is to print the entries on program
		//printf("%s %s %s %s %s %s %s\n", (table + i)->id, (table + i)->name.first, (table + i)->name.last, (table + i)->department, (table + i)->telephoneNum.extension, (table + i)->telephoneNum.personal, (table + i)->telephoneNum.house);
		fprintf(tel, "%s\t%s\t%s\t%s\t%s\t%s\t%s\n", (table + i)->id, (table + i)->name.first, (table + i)->name.last, (table + i)->department, (table + i)->telephoneNum.extension, (table + i)->telephoneNum.personal, (table + i)->telephoneNum.house);
		
		//printf("%d %d\n", newLineCount,i);
		i++;
	}
	
	printf("Success in rewriting tel.txt\n");
	fclose(tel);
	txtToStruct(table,lineCount);
	return;
}