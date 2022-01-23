#include "struct.h"
#include "function.h"

void sortDepartment(struct apuStaff* table,int* lineCount)
{
    int i, j, k;
    struct apuStaff store;
    for (i = 0; i < *lineCount-1; i++)
    {
        for (j = 0; j < *lineCount - i-1; j++)
        {
           /* k = 0;
            while (table[j].department[k] == table[j+1].department[k])
                k++;*/
             if (strcmp(table[j].department, table[j + 1].department) > 0)
            {
                store = table[j];
                table[j] = table[j + 1];
                table[j + 1] = store;
            }

        }
    }
  
    for (i = 0; i < *lineCount - 1; i++)//sort id
    {
        for (j = 0; j < *lineCount - i - 1; j++)
        {
            if (!strcmp(table[j].department, table[j + 1].department))
            {
                if (strcmp(table[j].id, table[j + 1].id)>0)
                {
                    store = table[j];
                    table[j] = table[j + 1];
                    table[j + 1] = store;
                }
            }
        }
    }

    return;
}

   