#ifndef employeeStruct
#define employeeStruct

struct apuStaff
{
	char id[7];
	struct
	{
		char first[31];
		char last[31];
	} name;
	char department[21];
	struct
	{
		char extension[6];
		char personal[15];
		char house[15];

	} telephoneNum;
};
#endif