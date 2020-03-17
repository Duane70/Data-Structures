#include"apc.h"

Slist *apc_addition( Slist *op1_head, Slist *op2_head )
{
    Slist *Result = NULL;

    reverse_list(&op1_head); reverse_list(&op2_head);

    int carry = 0, i , addition = 0;

    while( op1_head != NULL || op2_head != NULL )
    {
	addition = ( (op1_head ? (op1_head->data) : 0) + (op2_head ? (op2_head->data) : 0) + carry );
	//	printf("Sum: %d\n", addition);

	insert_first(&Result,(addition%10));
	carry = (addition >= 10)? 1 : 0;

	//	printf("carry: %d\n", carry);


	if(op1_head)
	    op1_head = op1_head->link;
	if(op2_head)
	    op2_head = op2_head->link;
    }

if(carry)
    insert_first(&Result,carry);

    reverse_list(&op1_head); reverse_list(&op2_head);
    return Result;
}

