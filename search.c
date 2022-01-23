#include "function.h"
#include "struct.h"
const char* searchKey()
{
	char* searchKey=malloc(63);
	printf("\nYou can only enter employee id or full name (first name+last name).\n");
	printf("Enter here: ");
	fgets(searchKey, 63, stdin);
	correctInput(searchKey, 63);
	return searchKey;
}

const char* departmentKey(int* lineCount, struct apuStaff *table)
{
	int i, j, departmentCount=0,tf,k;
	char department[100][50], departmentType[100][50];
	char* departmentKey = malloc(25);
	printf("\nYou can only enter department name.\n");
	printf("These are the department: ");
	for (i = 0; i < *lineCount; i++)//read all the departments including duplicate
	{
		strcpy(department[i], (table + i)->department);
	}
	for (i = 0; i < *lineCount; i++)
	{
		tf = 1;
		for (j = 0; j < departmentCount; j++)
		{
			if (strcmp(departmentType[j], department[i]) == 0)//to check if the department type already stored
				tf = 0;	
		}
		if (tf == 1)//if it is not sort then copy it to departmentType
		{
			strcpy(departmentType[departmentCount], department[i]);
			departmentCount++;
		}
	}
	for (k = 0; k < departmentCount ; k++)
	{
		printf("%s   ", departmentType[k]);//print the departments
	}
	printf("\n");
	printf("Enter here: ");
	fgets(departmentKey, 25, stdin);
	correctInput(departmentKey, 25);
	printf("\n");
	return departmentKey;
}

int searchTelephone(int* lineCount,struct apuStaff *table, char* key, int x)//when x=0, do not print details, only used to return which line the data is in
{
	
	char *searchName=malloc(63);
	int i, j=0;
	for (i = 0; i < *lineCount; i++)
	{
		sprintf(searchName, "%s %s", (table + i)->name.first, (table + i)->name.last);
		if (strcmp(key, (table + i)->id) == 0|| strcmp(key, searchName) == 0)
		{
			j++;
		}
		
	}
	
	if (j > 1)
	{
		j = 0;
		searchDuplicate(lineCount, table, key,0);
		printf("Employees with same name found. Please key in employee id for more precise search.\n");
		key=searchKey();
		searchTelephone(lineCount, table, key,x);
	}
	else if (j==0)
	{
		printf("No matched results.\n");
		if(x!=0)
		free(key);
		free(searchName);
		return -1;

	}
	else if (j == 1)
	{
		for (i = 0; i < *lineCount; i++)
		{
			sprintf(searchName, "%s %s", (table + i)->name.first, (table + i)->name.last);
			if (strcmp(key, (table + i)->id) == 0|| strcmp(key, searchName) == 0)
			{
				if (x == 1)//only print search result when x=1
				{
					printf("=========Search Result=========\n");
					printDetails(table + i, 0);
				}
				if (x != 0)//only free key when x!=0
				{
					free(key);
				}
				free(searchName);
				return i;
			}
			
		}
		
	}
	return 0;
	
}

int searchDepartment(int* lineCount, struct apuStaff* table, char* key)//int function so may be useful to obtain how many employees in department if needed
{

	int i, j = 0;

	for (i = 0; i < *lineCount; i++)
	{
		if (strcmp(key, (table + i)->department) == 0)
		{
			j++;
			if (j == 1)
			{
				printf("%10s%35s%35s%25s%20s%20s%20s\n", "EMPLOYEE ID", "FIRST NAME", "LAST NAME", "DEPARTMENT", "EXTENSION NUM", "PERSONAL P.NUM", "HOUSE P.NUM");//list format
			}
			printf("%10s%35s%35s%25s%20s%20s%20s\n", (table + i)->id, (table + i)->name.first, (table + i)->name.last, (table + i)->department, (table + i)->telephoneNum.extension, (table + i)->telephoneNum.personal, (table + i)->telephoneNum.house);
		}
	}
	if (j == 0)
	{
		printf("No matched results.\n");
		free(key);
		return -1;

	}
	else//just need it to return something so it is not -1
	{
		free(key);
		return i;
	}
}

int searchDuplicate(int* lineCount, struct apuStaff* table, char* key,int x)
{

	int i, j = 0;
	char *empName=malloc(63);
	char proceed, valid1 = 'F';
	char valid[100];
	for (i = 0; i < *lineCount; i++)
	{
		sprintf(empName, "%s %s", (table + i)->name.first, (table + i)->name.last);
		if (strcmp(key, empName) == 0)
		{
			j++;
			if (j == 1)
			{
				printf("\nDuplicate Name Found!\n");
				printf("%10s%35s%35s%25s\n", "EMPLOYEE ID", "FIRST NAME", "LAST NAME", "DEPARTMENT");
			}
			printf("%10s%35s%35s%25s\n", (table + i)->id, (table + i)->name.first, (table + i)->name.last, (table + i)->department);
		}
		else if (strcmp(key, (table + i)->telephoneNum.extension) == 0)
		{
			j++;

			if (j == 1)
			{
				printf("\nDuplicate Extension Number Found!\n");
				printf("%10s%35s%35s%25s%20s\n", "EMPLOYEE ID", "FIRST NAME", "LAST NAME", "DEPARTMENT","EXTENSION NUM");
			}
			printf("%10s%35s%35s%25s%20s\n", (table + i)->id, (table + i)->name.first, (table + i)->name.last, (table + i)->department, (table + i)->telephoneNum.extension);
		}

	}
	free(empName);

	if (j >=1&&x==1)
	{
		
		while (valid1 == 'F')
		{
			printf("\nDuplicate entry found. Press y to proceed, n to cancel this attempt, m to modify\n");
			proceed = getchar();
			if (proceed != '\n')
				gets(valid);

			while (!(proceed == 'y' || proceed == 'Y' || proceed == 'n' || proceed == 'N' || proceed == 'm' || proceed == 'M') || valid[0] != 0)
			{
				strcpy(valid, "");
				printf("Invalid Input. Please key in again!\n");
				proceed = getchar();
				if (proceed != '\n')
					gets(valid);
			}
			strcpy(valid, "");
			
			switch (proceed)
			{
				case 'Y':
				case 'y':
					valid1 = 'T';
					return 1;
					break;

				case 'N':
				case 'n':
					valid1 = 'T';
					return 0;
					break;

				case 'M':
				case 'm':
					valid1 = 'T';
					return 2;
					break;

				/*default:
					printf("Invalid Input. Please key in again! (Type character(s) if the program does not load options again)\n");
					break;*/
			}
		}
		
		
	}

	else if (j == 0)
	{
		if (x==1)
			printf("No duplicate entry found! ");
		return 1;

	}
	return 0;
}