#include"apc.h"

void reverse_list( Slist **head )
{
    Slist *prev = NULL, *current = *head, *next = NULL;

    while( current != NULL )
    {
	//Store adrress of next node
	next = current->link;

	//Reverse current nodes pointer
	current->link = prev;

	//Move pointer one position ahead
	prev = current;
	current = next;
    }
    *head = prev;
}

int insert_first(Slist **head, int data)
{
    //Declare pointer and allocate memory
    Slist *new1 = malloc(sizeof(Slist));
    //Validation
    if ( new1 == NULL )
	return FAILURE;

    new1->data = data;   //Insert data to node
    new1->link = *head;  //Insert address stored in head to the node link
    *head = new1;	 //Update head to point to new node link
    return SUCCESS;
}

int insert_last(Slist **head, int data)
{
    //Declare pointer and Allocatc memory
    Slist *new = malloc(sizeof(Slist));
    if ( new == NULL )  //Valdation
	return FAILURE;

    //Update node values
    new -> data = data;
    new -> link = NULL;

    //Check if list empty
    if ( *head == NULL )
    {
	*head = new;
	return SUCCESS;
    }

    //Traverse till last node
    Slist *temp = *head;

    while(temp->link != NULL )
    {
	temp = temp->link;
    }

    temp -> link = new;
    return SUCCESS;
}





void print_list( Slist *head )
{
    //Checking if list empty
    if ( head == NULL)
	printf("\nList is empty\n");
    else
    {
	while( (head != NULL) )
	{
	    if (head->data == '-')
	    printf("%c" ,head->data);
	    else
	    printf("%d" ,head->data);
	    head = head -> link;
	}
    }
}


