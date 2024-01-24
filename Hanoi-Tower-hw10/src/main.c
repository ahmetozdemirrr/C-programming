#include<stdio.h>
#include<stdlib.h>
#define STACK_BLOCK_SIZE 10

int move = 1; //We will use this global variable to keep the number of moves.

typedef struct
{
	int *array;
	int currentsize;
	int maxsize;
}stack;

int takePower(int x, int y) //We write a function for the power operation.
{
	int product = 1;

    for (int i = 1; i <= y; ++i)
    {
    	product *= x;
    }
    return product;
}

void push(stack *s, int d)
{
	move++; //Since the push and pop functions are called together in each move, we increment the move variable by one in any of them.
    
    s->array = (int *)realloc(s->array,sizeof(int)*(s->currentsize+1)); //We allocate a new place for each element added to the stack.
    s->array[s->currentsize] = d; //We throw the variable that comes as a parameter to the stack.
    (s->currentsize)++;
}

int pop(stack *s)
{
    int array = s->array[(s->currentsize)-1]; 
	s->array = (int *)realloc(s->array,sizeof(int)*s->currentsize-1); //We delete the old location of each element deleted from the stack from memory.
	s->currentsize--;
	
	return array;
}

stack * init_return()
{
    stack *stc = (stack *)malloc(sizeof(stack));
    stc->currentsize = 0;
    stc->array = (int *)malloc(sizeof(int)); //Here we allocate stack arrays in memory with malloc.

    return stc;
}

int init(stack *s)
{
    if (sizeof(s)==8) //Since sizeof(stack) = 8
    {
    	return 1;
    }
    return 0; //If the desired size is not allocated, we return zero.
}

int main(int argc, char const *argv[])
{
	int piece; //The variable to hold the deleted block with tha pop function.
    
    /*We allocate places in memory for stacks.*/
	stack *stack1 = init_return();	
	stack *stack2 = init_return();	
	stack *stack3 = init_return();

	if (!init(stack1) || !init(stack2) || !init(stack3)) //If system can not allocated place, we write a error message on terminal.
    {
    	printf("The Place Could Not Be Allocated!\n");
    }

    printf("\n\nEnter the maxsize: ");
    scanf("%d",&stack1->maxsize);
    
    stack1->array = (int *)malloc(sizeof(int)*stack1->maxsize);
    
    for (int i = 0; i < stack1->maxsize; ++i)
    {
    	stack1->array[i] = (STACK_BLOCK_SIZE)*(stack1->maxsize-i); //We fill the values in the array of stack1.
       	(stack1->currentsize)++;
    }
    printf("\n");

    while (move <= (takePower(2,stack1->maxsize)-1))
    {
    	switch(move%3)
	    {
	    	case 0:

	    	    if (((stack2->array[stack2->currentsize-1] < stack3->array[stack3->currentsize-1]) && (stack2->currentsize!=0)) || stack3->currentsize==0)
	    	    {
	    	    	piece = pop(stack2);
	    	    	push(stack3,piece);

	    	    	printf("Move the disk %d from '2' to '3'\n",piece/10);
	    	    }

	    	    else if (((stack2->array[stack2->currentsize-1] > stack3->array[stack3->currentsize-1]) && (stack3->currentsize!=0)) || stack2->currentsize==0)
	    	    {
	    	    	piece = pop(stack3);
	    	    	push(stack2,piece);

	    	    	printf("Move the disk %d from '3' to '2'\n",piece/10);
	    	    }
	    	break;

	    	case 1:
	    	    
	    	    if (((stack1->array[stack1->currentsize-1] < stack3->array[stack3->currentsize-1]) && (stack1->currentsize!=0)) || stack3->currentsize==0)
	    	    {
	    	    	piece = pop(stack1);
	    	    	push(stack3,piece);

	    	    	printf("Move the disk %d from '1' to '3'\n",piece/10);
	    	    }

	    	    else if (((stack1->array[stack1->currentsize-1] > stack3->array[stack3->currentsize-1]) && (stack3->currentsize!=0)) || stack1->currentsize==0)
	    	    {
	    	    	piece = pop(stack3);
	    	    	push(stack1,piece);

	    	    	printf("Move the disk %d from '3' to '1'\n",piece/10);
	    	    }
	    	break;

	    	case 2:

	    	    if (((stack2->array[stack2->currentsize-1] < stack1->array[stack1->currentsize-1]) && (stack2->currentsize!=0)) || stack1->currentsize==0)
	    	    {
	    	    	piece = pop(stack2);
	    	    	push(stack1,piece);

	    	    	printf("Move the disk %d from '2' to '1'\n",piece/10);
	    	    }

	    	    else if (((stack2->array[stack2->currentsize-1] > stack1->array[stack1->currentsize-1]) && (stack1->currentsize!=0)) || stack2->currentsize==0)
	    	    {
	    	    	piece = pop(stack1);
	    	    	push(stack2,piece);

	    	    	printf("Move the disk %d from '1' to '2'\n",piece/10);
	    	    }
	    	break;
	    }
    }
	return 0;
}