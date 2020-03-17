#include"apc.h"

Slist *apc_multiplication( Slist *op1_head, Slist *op2_head )
{
    Slist *Result = NULL,*temp_Result = NULL, *temp;

    reverse_list(&op1_head); reverse_list(&op2_head);

    int carry = 0, i=0 , multiplication = 0, append_zeroes_for_sum = 0;

    while( op2_head != NULL )
    {
	carry = 0;
	temp = op1_head;
	temp_Result = NULL;

	while( temp != NULL )
	{

	    multiplication = ( ((temp)? temp->data : 0) * ((op2_head) ? op2_head->data : 0 )) + carry;

//	    printf("Sum: %d\n", multiplication);


	    insert_first(&temp_Result,(multiplication)%10);
	    carry = (multiplication)/10;

//	    printf("carry: %d\n", carry);
	    temp = temp->link;
	}

	if(carry)
	    insert_first(&temp_Result,carry);


	for(i=0; i < append_zeroes_for_sum; i++ )
	    insert_last(&temp_Result,0);

//	printf("temp res");
//	print_list(temp_Result);	


	append_zeroes_for_sum += 1;

//	reverse_list(&temp_Result); reverse_list(&Result);

	Result = apc_addition(temp_Result,Result);
//	reverse_list(&temp_Result); reverse_list(&Result);

//	printf("res");
//	print_list(Result);	
	op2_head = op2_head->link;
    }

    //reverse_list(&Result);
    while(Result->data == 0 && Result->link != NULL)
    {
	temp = Result;
	Result = Result->link;
	free(temp);
    }
    
	if ( ((op1_minus_flag) && (!op2_minus_flag)) || ((op2_minus_flag) && (!op1_minus_flag)) )
	insert_first(&Result,'-');



return Result;
}

