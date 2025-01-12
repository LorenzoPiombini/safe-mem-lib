#include <stdio.h>
#include "safe_m.h"



int main(void)
{
	void* sp;
	GET_STACK_POINTER(sp);

	unsigned long* stack = (unsigned long*)sp;
		
	int size = 5;
	int*p = s_malloc(sizeof(int)*size);
	
	
	for(int j = 0; j < 80;j++)
	{	void* cur_add = (void *)stack[j];
 		
		if(cur_add == (void*)p)
		{	printf("\npointer p found on the stack!\n");
			break;
		}
	}

	/*
	 * check if s_malloc worked properly
	 * all the value should be 0
	 * 
	 * */
	for(int i = 0; i < size; i++)
		printf("array value at [%d] is %d.\n",i,p[i]);


	s_free(p);
	return 0;
}
