/*
 * This is the file in which you'll write the functions required to implement
 * a queue using two stacks.  Make sure to add your name and @oregonstate.edu
 * email address below:
 *
 * Name:Li Hung Chen
 * Email:chenlih@oregonstate.edu
 */

#include <stdio.h>
#include<stdlib.h>
#include "stack.h"
#include "queue_from_stacks.h"
#include<assert.h>
/*
 * This function should allocate and initialize all of the memory needed for
 * your queue and return a pointer to the queue structure.
 */
struct queue_from_stacks* queue_from_stacks_create() {
  struct queue_from_stacks* qfsc=malloc(sizeof(struct queue_from_stacks));	//alloc memories for qfsc
  qfsc->s1=stack_create();							//create two stacks
  qfsc->s2=stack_create();
  
  return qfsc;
}

/*
 * This function should free all of the memory allocated to a queue, including
 * the memory associated with each stack.
 *
 * Params:
 *   queue - the queue to be destroyed.  May not be NULL.  The function should
 *     exit the program with an error if queue is NULL.
 */
void queue_from_stacks_free(struct queue_from_stacks* queue) {
stack_free(queue->s1);
stack_free(queue->s2);
free(queue);
}

/*
 * This function should return 0 if a queue is completely empty or 1 if there
 * is at least one element stored in the queue.
 *
 * Params:
 *   queue - the queue whose emptiness is to be checked.  May not be NULL.
 *     The function should exit the program with an error if queue is NULL.
 *
 * Return:
 *   Should return 1 if the queue is empty or 0 otherwise.
 */
int queue_from_stacks_isempty(struct queue_from_stacks* queue) {
	 if(stack_isempty(queue->s1)&&stack_isempty(queue->s2)){	//check if s1 and s2 are all empty 
 		return 1;
 	 }
   else{
    return 0;
   }
}

/*
 * Should enqueue a new value onto the end of a queue.
 *
 * Params:
 *   queue - the queue onto which to enqueue a value.  May not be NULL.
 *     The function should exit the program with an error if queue is NULL.
 *   value - the new value to be enqueueed onto the queue
 */
void queue_from_stacks_enqueue(struct queue_from_stacks* queue, int value) {

	stack_push(queue->s1,value);

}

/*
 * Should return a queue's front value without removing that value from the
 * queue.
 *
 * Params:
 *   queue - the queue from which to read the front value.  May not be NULL or
 *     empty.  The function should exit the program with an error if queue is
 *     NULL or empty.
 *
 * Return:
 *   Should return the value stored at the front of the queue.
 */
int queue_from_stacks_front(struct queue_from_stacks* queue) {

	 if( stack_isempty(queue->s2) && ( !stack_isempty(queue->s1) )){ //check if all elements are in queue->s1 
	 	
    while( !stack_isempty(queue->s1) ){					 //to find the last one in the queue->s1
    stack_push(queue->s2, stack_pop(queue->s1));
    }
  }

  return stack_top(queue->s2);						 //return the last one 
}

/*
 * Should remove the front element from a queue and return its value.
 *
 * Params:
 *   queue - the queue from which to dequeue a value.  May not be NULL or
 *     empty.  The function should exit the program with an error if queue is
 *     NULL or empty.
 *
 * Return:
 *   Should return the value stored at the front of the queue before that value
 *   is dequeued.
 */
int queue_from_stacks_dequeue(struct queue_from_stacks* queue) {
	
	 if(!stack_isempty(queue->s2)){				//find the last one in the queue->s2 and return it
      return stack_pop(queue->s2);
     }
  else return 0;
}
