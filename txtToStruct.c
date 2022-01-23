#include "struct.h"
#include "function.h"

void txtToStruct(struct apuStaff* table, int* lineCount)
{
	int sizeStruct = sizeof(struct apuStaff)+14;
	int i = 0;
	char line[200];
	
	char* buf=0;
	FILE* tel = fopen("tel.txt", "r");
	
	if (tel == NULL)
	{
		printf("Error opening tel.txt. Program terminating...\n");
		exit(1);
	}
	printf("Reading...\n");

	while (fgets(line, sizeStruct+14, tel))
	{
		//printf("hi");
		buf = strtok(line, "\t");
		//printf("%s", buf);
		if (buf)
			strcpy((table + i)->id, buf);
		buf = strtok(NULL, "\t");
		if (buf)
			strcpy((table + i)->name.first, buf);
		buf = strtok(NULL, "\t");
		if (buf)
			strcpy((table + i)->name.last, buf);
		buf = strtok(NULL, "\t");
		if (buf)
			strcpy((table + i)->department, buf);
		buf = strtok(NULL, "\t");
		if (buf)
			strcpy((table + i)->telephoneNum.extension, buf);
		buf = strtok(NULL, "\t");
		if (buf)
			strcpy((table + i)->telephoneNum.personal, buf);
		buf = strtok(NULL, "\n");
		if (buf)
			strcpy((table + i)->telephoneNum.house, buf);
		//below code is to print the entries on program
		//printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\n", (table + i)->id, (table + i)->name.first, (table + i)->name.last, (table + i)->department, (table + i)->telephoneNum.extension, (table + i)->telephoneNum.personal, (table + i)->telephoneNum.house);
			i++;
	}

	*lineCount = i;
	printf("Success in reading tel.txt\n");
	fclose(tel);
	return;
}