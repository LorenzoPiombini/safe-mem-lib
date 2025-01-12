#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h" /* for AVL tree */
#include "linked_list.h" /* for ll (Linked_list) */
#include "safe_m.h"


Mem_dta _mdta = {{NULL,insert_bst},&ll};

void *s_malloc(size_t size)
{
	void* ptr = malloc(size);
	if(!ptr)
	{
		printf("s_malloc() failed.\n");
		exit(EXIT_FAILURE);
	}	

	/*set all the bytes to zero*/
	memset(ptr,0,size);

	/*saving data in the structure*/	
	long* sz =(long*)&size;
	_mdta.ptr_alloc.insert(t_v,ptr,&_mdta.ptr_alloc.root,(void**)&sz,t_l);
	
	/*saving data in the linked list*/
	if(_mdta.all_ptrs->length == 0)
	{
		/* initialized a linked list */
		ll_init(&ll,ptr,DYN);
	}
	else
	{
		/* apend the linked list with ptr returned from malloc */
		apend_ll(&ll,ptr,DYN);
	}

	return ptr;
		 		
}

void *s_calloc(size_t bytes, size_t size_type)
{

}

void *s_realloc(void* ptr,size_t size)
{


}

void s_free(void* ptr)
{
	long* sz = NULL;
	if(!find(t_v,ptr,&_mdta.ptr_alloc.root,(void**)&sz,t_l))
	{
		printf("pointer not allcated with safe lib.\n");
		return;
	}
	
	free(ptr);	
}

/*function to access the memory */
void *_ac_s_mem(void* ptr, size_t size, int mem_index)
{
	/* find the pointer in the tree
		if not return NULL
	*
	*/
}
