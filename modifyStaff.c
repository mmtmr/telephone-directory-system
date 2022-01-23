#include"struct.h"
#include"function.h"
void modifyStaff(struct apuStaff *table, int* lineCount)
{
	char* target;
	char valid[50];
	char attribute,exit=0;
	int x;
	target=searchKey();
	x = searchTelephone(lineCount, table, target, 0);
	
	if (x<0)
	{
		while (1)
		{
			printf("Enter q to exit, m to make another modification\n");
			exit = getchar();

			if (exit!='\n')
				gets(valid);

			if (valid[0] != 0)
			{
				//strcpy(valid, "");
				printf("Invalid Input. Please key in again!\n");
			}
			else if (exit == 'q' || exit == 'Q')
				return;
			else if (exit == 'm' || exit == 'M')
				return modifyStaff(table, lineCount); //recursive function
			else
				printf("Invalid Input. Please key in again!\n"); //written twice, first time will exlude the option of for example "qq", second time will exclude other options besides 'q' and 'm'
			strcpy(valid, "");
		}
		
	}
	else
	{
		printDetails((table + x), -1);
		attribute = modifyAttribute();

		if (attribute == 'q' || attribute == 'Q')
			return;
		else modifyDetails((table), attribute, lineCount, x, 0);
	}
	return;

}


char modifyAttribute()
{
	char choice;
	char valid[100];
	while (1)
	{
		printf("Which attribute do you want to modify?\n");
		printf("[1] First name\n[2] Last name\n[3] Department\n[4] Extension Number\n[5] Personal Phone Number\n[6] House Phone Number\nEnter q to quit\n");
		printf("Enter choice: ");
		choice = getchar();

		if (choice != '\n')
			gets(valid);

		if (valid[0] != 0)
		{
			strcpy(valid, "");
			printf("Invalid Input. Please key in again!\n\n");
		}
		else if (choice >= '1' && choice <= '6' || choice == 'q' || choice == 'Q')
			return choice;
		else
			printf("Invalid Input. Please key in again!\n\n");
		strcpy(valid, "");
	}
	return;

}

void modifyDetails(struct apuStaff* table, char choice, int* lineCount,int position, int x)
{
	//the x, if 0, stands for directly call function to modify employee details from main menu.
	//the x, if 1, stands for call function to modify employee details from creating new entries.
	char option, valid1 = 'F', valid2 = 'F';
	char valid[100], fullName[63];
	int duplicateExt=0, duplicateName=0, newPosition;
	char* oldName = malloc(63);
	char* id = malloc(10);
	char* temp = malloc(10);
	struct apuStaff S;//for the size
	announceRules();
	sprintf(fullName, "%s %s", (table + position)->name.first, (table + position)->name.last);
	strcpy(oldName, fullName);//to exclude own name when searching for duplicate
	strcpy(id, (table + position)->id);//to save id before sorting the data
	switch(choice)
	{
		case '1':
			printf("Change first name to: ");
			fgets((table + position)->name.first, sizeof(S.name.first), stdin);
			correctInput((table + position)->name.first, sizeof(S.name.first));
			break;
		case '2':
			printf("Change last name to: ");
			fgets((table + position)->name.last, sizeof(S.name.last), stdin);
			correctInput((table + position)->name.last, sizeof(S.name.last));
			break;
		case '3':
			printf("Change department to: ");
			fgets((table + position)->department, sizeof(S.department), stdin);
			correctInput((table + position)->department, 1);
			newPosition = searchTelephone(lineCount, table, id, 0);
			break;
		case '4':
			do
			{
				printf("Change phone extension number to: ");
				fgets(temp, sizeof(S.telephoneNum.extension), stdin);
				correctInput(temp, sizeof(S.telephoneNum.extension));
				if (strcmp(temp, (table + position)->telephoneNum.extension) != 0)
				{
					printf("Checking for duplicate extension number...\n");
					duplicateExt = searchDuplicate(lineCount, table, temp, 1);
				}
				else
					duplicateExt = 1;

				if (duplicateExt == 1)
				{
					strcpy((table + position)->telephoneNum.extension, temp);
					printf("Continue...\n\n");
				}				
				else if (duplicateExt == 0)
					valid1 = 'T';			
			} while (duplicateExt == 2);
			break;
		case '5':
			printf("Change personal phone to: ");
			fgets((table+position)->telephoneNum.personal, sizeof(S.telephoneNum.personal), stdin);
			correctInput((table+position)->telephoneNum.personal, 0);
			break;
		case '6':
			printf("Change house phone to: ");
			fgets((table+position)->telephoneNum.house, sizeof(S.telephoneNum.house), stdin);
			correctInput((table+position)->telephoneNum.house, 0);
			break;
	}
	sprintf(fullName, "%s %s", (table + position)->name.first, (table + position)->name.last);
	if ((choice == '1' || choice == '2')&& strcmp(oldName,fullName) != 0)
	{

		do
		{
			printf("Checking for duplicate name...\n");
			
			duplicateName = searchDuplicate(lineCount, table, fullName, 1);

			if (duplicateName == 1)
				printf("Continue...\n\n");

			else if (duplicateName == 0)
				valid1 = 'T';
			
			else if (duplicateName == 2)
			{
				printf("Change first name to: ");
				fgets((table + position)->name.first, sizeof(S.name.first), stdin);
				correctInput((table + position)->name.first, sizeof(S.name.first));

				printf("Change last name to: ");
				fgets((table + position)->name.last, sizeof(S.name.last), stdin);
				correctInput((table + position)->name.last, sizeof(S.name.last));
			}
		}while (duplicateName == 2);

	}
	free(temp);

	printf("\n=========Result=========\n");
	printDetails((table+position), -1);
	while (valid1 == 'F'&&x==0)
	{
		printf("Enter y to save this modificiation\nEnter c to dicard this modification\n");
		option = getchar();
		if (option != '\n')
			gets(valid);
		while (!(option=='y' || option == 'Y' || option == 'c' || option == 'C')||valid[0] != 0)
		{
			strcpy(valid, "");
			printf("Invalid Input. Please key in again!\n");
			option = getchar();
			if (option != '\n')
				gets(valid);
		}
		strcpy(valid, "");
		switch (option)
		{
			case 'y':
			case 'Y':
				structToTxt(table, lineCount);
				newPosition = searchTelephone(lineCount, table, id, 0);
				printf("Save modifictaion success.\n");
				valid1 = 'T';
				break;

			case 'c':
			case 'C':
				txtToStruct(table, lineCount);
				newPosition = searchTelephone(lineCount, table, id, 0);
				printf("Cancel modification success.\n");
				valid1 = 'T';
				break;
		//default:
		//	printf("Invalid input.");
		//	break;
		}
	}
	if (x == 1) //does not provide cancel modification from addEmployee function
	{
		structToTxt(table, lineCount);
		printf("Save modifictaion success.\n");
	}
	while (valid2 == 'F'&&x==0)
	{
		printf("Enter x to modify details of this employee\nEnter n to modify another employee\nEnter q to return to main menu\n");
		option = getchar();
		if (option != '\n')
			gets(valid);
		while (!(option == 'x' || option == 'X' || option == 'n' || option == 'N' || option == 'q' || option == 'Q') || valid[0] != 0)
		{
			strcpy(valid, "");
			printf("Invalid Input. Please key in again!\n");
			option = getchar();
			if (option != '\n')
				gets(valid);
		}
		strcpy(valid, "");
		switch (option)
		{
			case 'x':
			case 'X':
				valid2 = 'T';
				newPosition = searchTelephone(lineCount, table, id, 0);
				//printf("New position %d", newPosition);
				return modifyDetails((table), modifyAttribute(), lineCount, newPosition, 0);
				break;
			case 'n':
			case 'N':
				valid2 = 'T';
				free(id);
				free(oldName);
				return modifyStaff(table, lineCount);
				break;

			case 'q':
			case 'Q':
				valid2 = 'T';
				free(id);
				free(oldName);
				break;
			//default:
			//	printf("Invalid Input.\n");
			//	break;
		}
	}
	while (valid2 == 'F' && x == 1)
	{
		printf("Enter x to modify another details of this employee\nEnter q to return to main menu\n");
		option = getchar();
		if (option != '\n')
			gets(valid);
		while (!(option == 'x' || option == 'X' || option == 'q' || option == 'Q') || valid[0] != 0)
		{
			strcpy(valid, "");
			printf("Invalid Input. Please key in again!\n");
			option = getchar();
			if (option != '\n')
				gets(valid);
		}
		switch (option)
		{
			case 'x':
			case 'X':
				valid2 = 'T';
				newPosition = searchTelephone(lineCount, table, id, 0);
				return modifyDetails((table), modifyAttribute(), lineCount, newPosition, 1);
				break;

			case 'q':
			case 'Q':
				free(id);
				free(oldName);
				valid2 = 'T';
				break;

			/*default:
				printf("Invalid Input.\n");
				break;*/
		}
	}
		return;

}
