#include "struct.h"
#include "function.h"

void addStaff(struct apuStaff* table, int* lineCount)
{
	int i = *lineCount, k = 0, duplicateName = 0, duplicateExt = 0, newPosition, sizeStruct = sizeof(struct apuStaff) + 14;
	char idPrefix[4], fullName[63], valid[100];
	char* id = malloc(10);
	struct apuStaff S;//to check size
	char choice, valid1 = 'F', attribute;

	announceRules();

	sprintf(idPrefix, "%d", i + 1);
	strcpy((table + i)->id, "AP");
	while ((k + strlen(idPrefix)) != 3) //to add leading zeros
	{
		k++;
		strcat((table + i)->id, "0");
	}
	k = 0;
	strcat((table + i)->id, idPrefix);
	strcpy(id, (table + i)->id);
	//free(id);
	printf("Inputting %s Details\n", id);
	do
	{
		printf("First Name is: ");
		fgets((table + i)->name.first, sizeof(S.name.first), stdin);//use fgets to ensure input won't overflow
		correctInput((table + i)->name.first, sizeof(S.name.first));//to delete the '\n', add - for blank input, and convert input to uppercase 

		printf("Last Name is: ");
		fgets((table + i)->name.last, sizeof(S.name.last), stdin);
		correctInput((table + i)->name.last, sizeof(S.name.first));

		sprintf(fullName, "%s %s", (table + i)->name.first, (table + i)->name.last);
		if (*lineCount != 0) //not new file, check duplicate
		{
			printf("Checking for duplicate name...\n");
			duplicateName = searchDuplicate(lineCount, table, fullName, 1);
		}
		else if (*lineCount == 0) //new file, don't check duplicate
		{
			duplicateName = 1;
		}

		if (duplicateName == 1 && *lineCount != 0)
			printf("Continue...\n\n");

	} while (duplicateName == 2);//Modify name

	if (duplicateName == 1)
	{
		printf("Current department is: ");
		fgets((table + i)->department, sizeof(S.department), stdin);
		correctInput((table + i)->department, sizeof(S.department));

		do
		{
			printf("Office phone extension number is: ");
			fgets((table + i)->telephoneNum.extension, sizeof(S.telephoneNum.extension), stdin);
			correctInput((table + i)->telephoneNum.extension, sizeof(S.telephoneNum.extension));

			if (*lineCount != 0) //not new file, check duplicate
			{
				printf("Checking for duplicate extension number...\n");
				duplicateExt = searchDuplicate(lineCount, table, (table + i)->telephoneNum.extension, 1);
			}
			else if (*lineCount == 0) //new file, don't check duplicate
			{
				duplicateExt = 1;//Proceed
			}

			if (duplicateExt == 1 && *lineCount != 0)
				printf("Continue...\n\n");

		} while (duplicateExt == 2);//Modify extension number

		if (duplicateExt == 1)
		{
			printf("Personal phone is : ");
			fgets((table + i)->telephoneNum.personal, sizeof(S.telephoneNum.personal), stdin);
			correctInput((table + i)->telephoneNum.personal, 0);

			printf("House phone is: ");
			fgets((table + i)->telephoneNum.house, sizeof(S.telephoneNum.house), stdin);
			correctInput((table + i)->telephoneNum.house, 0);
			printf("\n");
		}

	}

	if (duplicateExt == 1)
	{
		printf("=========Confirmation=========\n");
		printDetails(table + i, -1);

		while (valid1 == 'F')
		{
			printf("Enter y to save this input\nEnter m to save and modify this input\nEnter c to discard this input\n");
			choice = getchar();
			if (choice != '\n')
				gets(valid);
			while (!(choice == 'y' || choice == 'Y' || choice == 'c' || choice == 'C' || choice == 'm' || choice == 'M') || valid[0] != 0)
			{
				strcpy(valid, "");
				printf("Invalid Input. Please key in again!\n");
				choice = getchar();
				if (choice != '\n')
					gets(valid);
			}
			strcpy(valid, "");
			switch (choice)
			{
			case 'y':
			case 'Y':
				valid1 = 'T';
				*lineCount = i;
				*lineCount += 1;
				structToTxt(table, lineCount);
				printf("Save new entry success.\n");
				break;

			case 'm':
			case 'M':
				valid1 = 'T';
				*lineCount = i;
				*lineCount += 1;
				sortDepartment(table, lineCount);
				structToTxt(table, lineCount);
				printf("Save new entry success. Modifying...\n");
				modifyDetails(table, modifyAttribute(), lineCount, searchTelephone(lineCount, table, id, 0), 1);

				break;
			case 'c':
			case 'C':
				valid1 = 'T';
				printf("Cancel new entry success.\n");
				break;

				/*default:
					printf("Invalid Input. Please key in again! (Type character(s) if the program does not load options again)\n");
					break;*/
			}
		}
	}
}
