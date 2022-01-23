#include"struct.h"
#include"function.h"

void printDetails(struct apuStaff* table, int i)
{
	//struct apuStaff S;
	if (i <0)
	{
		printf("Employee ID is %s\n", (table->id));
		printf("Name is %s %s\n", (table)->name.first, (table)->name.last);
		printf("Current department is %s\n", (table)->department);
	}
	printf("Office phone number is +60389961000 (Ext. %s)\n", (table)->telephoneNum.extension);
	if (verifyDetails(table->telephoneNum.personal) == 'T')//only print if not empty
		printf("Personal phone number is +6%s\n", (table)->telephoneNum.personal);
	if (verifyDetails(table->telephoneNum.house) == 'T')
		printf("House phone number is +6%s\n", (table)->telephoneNum.house);

	printf("\n");
}

