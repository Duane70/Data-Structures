#include"apc.h"


int main(int argc, char *argv[])
{
    //Checking number of arguments passed in command line
    if ( argc <= 3 || argc > 4 )
    {
	printf("Please provide command line arguments eg. 10 + 7\n");
	return 0;
    }

    //Initializing Slist head of operand1 and operand2 respc
    Slist *op1_head = NULL, *op2_head = NULL;


    //Storing the operands in char array
    char operand1[MAX], *operator , operand2[MAX];
    
    strcpy(operand1,argv[1]);
    //Eliminating preceeding zeroes from the input string 
    my_strrev(operand1);
    for(int i = (strlen(operand1)-1); operand1[i] == '0'; i-- )
    {
	operand1[i] = '\0';
    }
    my_strrev(operand1);
    //Calculating length of operand_1
    unsigned int op1_length = strlen(operand1);
    //Checking the operand for numeric digits only
    int status = check_exp(operand1,&op1_head);
    if( status == MINUS_FLAG );
    op1_minus_flag = 1;


    strcpy(operand2,argv[3]);
    //Eliminating preceeding zeroes from the input string 
    my_strrev(operand2);
    for(int i = (strlen(operand2)-1); operand2[i] == '0'; i-- )
    {
	operand2[i] = '\0';
    }
    my_strrev(operand2);
    unsigned int op2_length = strlen(operand2); 
    status = check_exp(operand2,&op2_head);
    if( status == MINUS_FLAG );
    op2_minus_flag = 1;


    //Storing character in char variable
    operator = argv[2]; 
    check_operator(operator);


    print_list(op1_head);
    printf(" %c ",*operator);
    print_list(op2_head);
    printf(" = ");
    if ( *operator == '+' )
    {
	Slist *Result = apc_addition(op1_head,op2_head);
	print_list(Result);
    }
    else if ( *operator == '-' )
    {

	//Comparing length of operands
	if ( op1_length  > op2_length )
	{
	    int diff = op1_length - op2_length;

	    for (int i = 0; i < diff; i++)
		insert_first(&op2_head,0);

	}	
	else if ( op2_length  > op1_length )
	{
	    int diff = op2_length - op1_length;

	    for (int i = 0; i < diff; i++)
		insert_first(&op1_head,0);
	}



	Slist *Result = apc_subtraction(op1_head,op2_head);
	print_list(Result);

    }
    else if ( *operator == 'x' )
    {

	Slist *Result = apc_multiplication(op1_head,op2_head);
	print_list(Result);

    }
   /*
    else if ( *operator == '/' )
    {

	Slist *Result = apc_division(op1_head,op2_head);
	print_list(Result);

    }
*/

    return 0;
}















