#include "struct.h"
#include "function.h"

void mainMenu(int* lineCount, struct employeeID *table)
{
	char choice, valid[100];
	int i;
	printf("\n=========Main Menu=========\n");
	printf("Which function do you want to perform?\n");
	printf("[1] Search Employee Phone Number\n");
	printf("[2] Create New Employee and Phone Number Entry\n");
	printf("[3] Modify Existing Employee Details\n");
	printf("[4] Produce Department Employee List\n");
	printf("[0] Quit\n");
	choice = getchar();
	if (choice!='\n') //To avoid double input
		gets(valid);
	while ((choice < '0') || (choice > '4') ||(valid[0]!=0))
	{
		//Verify input. Input choice must be in range of 0 and 4 and valid must be empty to ensure input is not for example "12"
		strcpy(valid, "");
		printf("Invalid Input. Please key in again!\n");
		choice = getchar();
		if (choice != '\n')
			gets(valid);
	}
	strcpy(valid, "");
	switch (choice)
	{
		case '1':
			searchTelephone(lineCount, table, searchKey(),1);
			break;
		case '2':
			addStaff(table, lineCount);
			break;
		case '3':
			modifyStaff(table, lineCount);
			break;
		case '4':
			searchDepartment(lineCount, table,departmentKey(lineCount, table));
			break;
		case '0':
			printf("Good day!\n");//Goodbye message
			exit(0);
			break;
		default://Technically won't be used due to the while loop up there
			printf("Invalid Input. Please key in again!");
	}
	return;
}