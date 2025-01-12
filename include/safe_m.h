/* this is FREE software, it is part of an efort to keep
	the C programming language safe and used, to help 
	c developers avoiding to learn new safer languages like RUST
	if they do not want to do so, this is my personal take in response of the
 	recent articles pubblished from governaments agencies, regarding the delicate
	issue of memory safe languages and memory vulnerablility.
	please visit www.theCsafeproject.io for more info.

Author: Lorenzo Piombini
Dec. 2024
*/ 

#ifndef _SAFE_M_H_
#define _SAFE_M_H_

/* for architecture macros */
#include <stdio.h>

/* for AVL tree */
#include "bst.h"

/* for ll (Linked_list) */
#include "linked_list.h"

/*check the machine architecture 
 *and define the appropriate assembly 
 */

#if defined(__x86_64__)
	#define GET_STACK_POINTER(sp) asm("mov %%rsp, %0" : "=r"(sp))

#elif defined(__i386__)
	#define GET_STACK_POINTER(sp) asm("mov %%esp, %0" : "=r"(sp)) 

#elif defined(__aarch64__)
	#define GET_STACK_POINTER(sp) asm("mov %0, sp" : "=r"(sp)) 

#elif defined(__arm__)
	#define GET_STACK_POINTER(sp) asm("mov %0, sp" : "=r"(sp))

#elif defined(__riscv)
	#define GET_STACK_POINTER(sp) asm("mov %0, sp": "=r"(sp)) 

#else
	#error "unkown architecture"
#endif


/* struct for memory info */
typedef struct
{
	BST ptr_alloc;		/*AVL tree to optimize search */
	Linked_list* all_ptrs;   /* linked list to contain all the pointers for free all the memory at once */
}Mem_dta;


extern Mem_dta _mdta;
extern unsigned char ht_status;

/* wrappers for the std allocators as in GLIBC */
void *s_malloc(size_t size);
void *s_calloc(size_t bytes, size_t size_type);
void *s_realloc(void* ptr,size_t size);

/* safe memory access */
void *_ac_s_mem(void* ptr, size_t size, int mem_index);


void s_free(void* ptr);

#endif /* safe_m.h */
