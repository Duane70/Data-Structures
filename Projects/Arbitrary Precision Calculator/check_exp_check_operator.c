#include"apc.h"

int check_exp(char *operand, Slist **head)
{
    int addition = 0;
    int str_index = (strlen(operand)) - 1;  //since we access exp using array

    while(str_index >= 0 )
    {
	//	if( minus_flag == 1 && str_index == 0 )
	//	    break;

	//Checking signedness of operand
	if ( operand[str_index] == '-' && str_index == 0 )
	    return MINUS_FLAG;

	//Checking for non-integer characters
	if( (operand[str_index] >= 0 &&  operand[str_index] <= 47) || (operand[str_index] >= 58 && operand[str_index] <= 127))
	{
	    printf("Error: Invalid operand !!\n");
	    exit(1);
	}

	insert_first(head,atoi(&operand[str_index]));
	operand[str_index] = '\0' ;
	str_index--;
    }
}

void check_operator(char *operator)
{
    if ( *operator != '+' && *operator != '-' && *operator != '*' && *operator != '/' && *operator != 'x') 
    {
	printf("Error: Invalid operator !!\n");
	exit(1);
    }
}
