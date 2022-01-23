#include "struct.h"
#include "function.h"

//struct apuStaff example1()
//{
//	struct apuStaff S[50];
//	strcpy_s(S[0].id, sizeof(S[0].id),"AP001");
//	strcpy_s(S[0].name.first, sizeof(S[0].name.first), "Alex");
//	strcpy_s(S[0].name.last, sizeof(S[0].name.last), "Beckham");
//	strcpy_s(S[0].telephoneNum.extension, sizeof(S[0].telephoneNum.extension), "0058");
//	strcpy_s(S[0].telephoneNum.personal.prefix, sizeof(S[0].telephoneNum.personal.prefix), "011");
//	strcpy_s(S[0].telephoneNum.personal.number, sizeof(S[0].telephoneNum.personal.number), "2345678");
//	strcpy_s(S[0].telephoneNum.house.prefix, sizeof(S[0].telephoneNum.house.prefix), "082");
//	strcpy_s(S[0].telephoneNum.house.number, sizeof(S[0].telephoneNum.house.number), "20000");
//	strcpy_s(S[0].department, sizeof(S[0].department), "Maths");
//	return S[0];
//}
//struct apuStaff example2()
//{
//	struct apuStaff S[50];
//	strcpy_s(S[1].id, sizeof(S[1].id), "AP002");
//	strcpy_s(S[1].name.first, sizeof(S[1].name.first), "Mohammed");
//	strcpy_s(S[1].name.last, sizeof(S[1].name.last), "Bin Abdul");
//	strcpy_s(S[1].department, sizeof(S[1].department), "Computing");
//	strcpy_s(S[1].telephoneNum.extension, sizeof(S[0].telephoneNum.extension), "0108");
//	strcpy_s(S[1].telephoneNum.personal.prefix, sizeof(S[0].telephoneNum.personal.prefix), "011");
//	strcpy_s(S[1].telephoneNum.personal.number, sizeof(S[0].telephoneNum.personal.number), "22446688");
//	strcpy_s(S[1].telephoneNum.house.prefix, sizeof(S[0].telephoneNum.house.prefix), "03");
//	strcpy_s(S[1].telephoneNum.house.number, sizeof(S[0].telephoneNum.house.number), "19990000");
//
//	return S[1];
//}
void printExample(struct apuStaff* table)
{
	int i;
	struct apuStaff S[10];
	S[0]=table[0];
	S[1] = table[1];
	S[2] = table[2];
	for (i = 0; i <3; i++)
	{
		printf("=========Staff No.%d=========\n", i + 1);
		printf("Employee ID is %s\n", S[i].id);
		printf("Name is %s %s\n", S[i].name.first, S[i].name.last);
		printf("Office phone number is +603-89961000 (Ext. %s)\n", S[i].telephoneNum.extension);
		printf("Personal phone number is +6%s\n", S[i].telephoneNum.personal);
		printf("House phone number is +6%s\n", S[i].telephoneNum.house);
		printf("Current department is %s\n", S[i].department);
	}
	
	return;
}