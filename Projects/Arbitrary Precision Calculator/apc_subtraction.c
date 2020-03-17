#include"apc.h"

Slist *apc_subtraction( Slist *op1_head, Slist *op2_head )
{
    Slist *Result = NULL;
	
    int op2_greater = 0;
 if(op2_head->data > op1_head->data)
    {
	op2_greater = 1;

	Slist *temp = op1_head;
	op1_head = op2_head;
	op2_head = temp;
    }
    
 reverse_list(&op1_head); reverse_list(&op2_head);

    int borrow = 0, i , subtraction = 0;

    while( op1_head != NULL )
    {
	if(op1_head->data < op2_head->data)
	{
	    op1_head->data =  (op1_head->data + 10);
//	    printf("\nxxxx%dxxxx",op1_head->data);
	    --(op1_head->link->data);
	}

	subtraction = ( (op1_head) ? (op1_head->data) : 0 ) - ( (op2_head) ? (op2_head->data) : 0 );	
//	    	printf("Sum: %d\n", subtraction);

	insert_first(&Result,subtraction%10);

//		printf("borrow: %d\n", borrow);

	op1_head = op1_head->link;
	op2_head = op2_head->link;
    }

    if (op2_greater)
	insert_first(&Result,'-');


    return Result;
}



