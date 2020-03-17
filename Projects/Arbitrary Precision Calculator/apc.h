#ifndef APC_H
#define APC_h

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 1000
#define FAILURE -1
#define SUCCESS -2
#define MINUS_FLAG -3
int op1_minus_flag, op2_minus_flag;

typedef struct node
{
    int data;
    struct node *link;
}Slist;


int check_exp(char *operand, Slist **head);
void check_operator(char *operator);
int insert_first(Slist **head, int data);
int insert_last(Slist **head, int data);
void print_list( Slist *head );
void reverse_list( Slist **head );
void my_strrev( char *s );

Slist *apc_addition( Slist *op1_head, Slist *op2_head ); 
Slist *apc_subtraction( Slist *op1_head, Slist *op2_head ); 
Slist *apc_multiplication( Slist *op1_head, Slist *op2_head);
Slist *apc_division(Slist *op1_head, Slist *op2_head);

#endif
