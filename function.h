#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void addStaff(struct apuStaff* table, int* lineCount);
void txtToStruct(struct apuStaff* table, int* lineCount);
void countLineAndReadTxt(int* lineCount);
void structToTxt(struct apuStaff* table, int* newLineCount);
void correctInput(char* input, int need);
void printDetails(struct apuStaff* table, int i);
char verifyDetails(char* key);
int searchTelephone(int* lineCount, struct apuStaff* table,char* key,int x);
void modifyStaff(struct apuStaff* table, int* lineCount);
char modifyAttribute();
void modifyDetails(struct apuStaff* table, char choice, int* lineCount, int position, int x);
const char* searchKey();
void mainMenu(int* lineCount, struct employeeID* table);
void announceRules();
int searchDepartment(int* lineCount, struct apuStaff* table, char* key);
const char* departmentKey(int* lineCount, struct apuStaff* table);
int searchDuplicate(int* lineCount, struct apuStaff* table, char* key, int x);
void sortDepartment(struct apuStaff* table, int* lineCount);
