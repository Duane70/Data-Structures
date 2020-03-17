#include"apc.h"

void my_strrev( char *str )
{
    int i = 0, j = (strlen(str) - 1);
    char temp;

    while(i < j)
    {
	temp = str[i];
	str[i] = str[j];
	str[j] = temp;
	i++;
	j--;
    }


}

