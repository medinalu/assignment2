/*
 * In this file, you will write the structures and functions needed to
 * implement a priority queue.  Feel free to implement any helper functions
 * you need in this file to implement a priority queue.  Make sure to add your
 * name and @oregonstate.edu email address below:
 *
 * Name: Luiz Medina
 * Email: medinalu@oregonstate.edu
 */

#include <stdlib.h>

#include "pq.h"
#include "dynarray.h"
#include <stdio.h>
#include <math.h>

/*
 * This is the structure that represents a priority queue.  You must define
 * this struct to contain the data needed to implement a priority queue.
 */
struct pq{
	struct dynarray* array;

};

struct pq_node{
	void* val;
	int priority_val;

};

/*
 * This function should allocate and initialize an empty priority queue and
 * return a pointer to it.
 */
struct pq* pq_create() {
	struct pq* new_pq = malloc(sizeof(struct pq));
	new_pq->array = dynarray_create();
	return new_pq;
}


/*
 * This function should free the memory allocated to a given priority queue.
 * Note that this function SHOULD NOT free the individual elements stored in
 * the priority queue.  That is the responsibility of the caller.
 *
 * Params:
 *   pq - the priority queue to be destroyed.  May not be NULL.
 */
void pq_free(struct pq* pq) {
	dynarray_free(pq->array);
	free(pq);
}


/*
 * This function should return 1 if the specified priority queue is empty and
 * 0 otherwise.
 *
 * Params:
 *   pq - the priority queue whose emptiness is to be checked.  May not be
 *     NULL.
 *
 * Return:
 *   Should return 1 if pq is empty and 0 otherwise.
 */
int pq_isempty(struct pq* pq) {
	if (pq->array->size == 0){	
		return 1;
	}
	return 0;
}


int leftchild_val(int pos, struct pq* pq){
	int k = pos*2+1;
	if (k<=dynarray_size(pq->array)){
		struct pq_node* b = pq->array->data[k];
        	return b->priority_val;	
	}
	else{
		return -1;
	}
}

int rightchild_val(int pos, struct pq* pq){
	int k = pos*2+2;
	if (k<=dynarray_size(pq->array)){
		struct pq_node* b = pq->array->data[k];
        	return b->priority_val;	
	}
	else{
		return -1;
	}
}

int parent_val(int pos, struct pq* pq){
	int k = (pos-1)/2;
	if (k>=0 && k<dynarray_size(pq->array)){
		struct pq_node* b = pq->array->data[k];
        	return b->priority_val;	
	}
}

int smallest_val(int b, int c){
	if (b<c){
		return b;
	}
	return c;
}


int check_if_children_smaller_then_parent(struct pq* pq, int pos){
	int left_index = floor(2*pos+1);
	int right_index = floor(2*pos+2);
	if (right_index < pq->array->size && left_index < pq->array->size){
		int right_val = rightchild_val(pos, pq);
        	int left_val = leftchild_val(pos, pq);
		struct pq_node* k = pq->array->data[pos];
		int pos_val = k->priority_val;
		int smallest_child_node_val = smallest_val(left_val,right_val);
		if (pos_val>smallest_child_node_val){
			return 1;
		}
		return 0;
	}
	else if(right_index < pq->array->size && left_index > pq->array->size){
		int right_val = rightchild_val(pos, pq);
                struct pq_node* k = pq->array->data[pos];
                int pos_val = k->priority_val;
                if (pos_val>right_val){
                        return 1;
                }
                return 0;
	}
	else if(left_index < pq->array->size && right_index > pq->array->size){
		int left_val = leftchild_val(pos, pq);
                struct pq_node* k = pq->array->data[pos];
                int pos_val = k->priority_val;
                if (pos_val>left_val){
                        return 1;
                }
                return 0;
        }
}


void perculate_down(struct pq* pq, struct pq_node* node,int pos){
        if (dynarray_size(pq->array) > 1){
                int pos_change = pos;
                while(check_if_children_smaller_then_parent(pq, pos_change)){
			int left_index = floor(leftchild_index(pos_change));
			int right_index = floor(rightchild_index(pos_change));
			if (left_index < pq->array->size && right_index < pq->array->size){
				int right_val = rightchild_val(pos_change, pq);
                        	int left_val = leftchild_val(pos_change,pq);
				if (left_val < right_val && node->priority_val>left_val){
                                	struct pq_node* temp1 = pq->array->data[pos_change];
                                	pq->array->data[pos_change] = pq->array->data[left_index];
                                	pq->array->data[left_index] = temp1;
                                	pos_change = left_index;
                        	}	
				else if(right_val < left_val && node->priority_val>right_val){
					struct pq_node* temp1 = pq->array->data[pos_change];
                                	pq->array->data[pos_change] = pq->array->data[right_index];
                                	pq->array->data[right_index] = temp1;
                                	pos_change = right_index;
				}
				else if(right_val == left_val && node->priority_val >left_val){
					struct pq_node* temp1 = pq->array->data[pos_change];
                                        pq->array->data[pos_change] = pq->array->data[left_index];
                                        pq->array->data[left_index] = temp1;
                                        pos_change = left_index;
				}
			}
			else if(left_index < pq->array->size && right_index > pq->array->size){
				int left_val = leftchild_val(pos_change,pq);
				if (node->priority_val > left_val){
					struct pq_node* temp1 = pq->array->data[pos_change];
                                	pq->array->data[pos_change] = pq->array->data[left_index];
                                	pq->array->data[left_index] = temp1;
                                	pos_change = left_index;
				}

			}
			else{
				break;
			}	
                }
	}
}


void perculate_up(struct pq* pq, struct pq_node* node,int pos){
	if (dynarray_size(pq->array) > 1){
		int pos_change = pos;
		int p_index = floor((pos_change-1)/2);
		if(p_index>=0 && p_index<pq->array->size){
        		while(node->priority_val < parent_val(pos_change, pq)){
				struct pq_node* temp1 = pq->array->data[pos_change];
				pq->array->data[pos_change] = pq->array->data[p_index];
				pq->array->data[p_index] = temp1;
				pos_change = p_index;
				p_index = (pos_change - 1) / 2;

 			}
		}
        }
}

/*
 * This function should insert a given element into a priority queue with a
 * specified priority value.  Note that in this implementation, LOWER priority
 * values are assigned to elements with HIGHER priority.  In other words, the
 * element in the priority queue with the LOWEST priority value should be the
 * FIRST one returned.
 
 * Params:
 *   pq - the priority queue into which to insert an element.  May not be
 *     NULL.
 *   value - the value to be inserted into pq.
 *   priority - the priority value to be assigned to the newly-inserted
 *     element.  Note that in this implementation, LOWER priority values
 *     should correspond to elements with HIGHER priority.  In other words,
 *     the element in the priority queue with the LOWEST priority value should
 *     be the FIRST one returned.
 */
void pq_insert(struct pq* pq, void* value, int priority) {
	if (pq != NULL){
		struct pq_node* element = malloc(sizeof(struct pq_node));
		element->val = value;
		element->priority_val = priority;
		dynarray_insert(pq->array,element);
		perculate_up(pq, element,pq->array->size-1);
	}	
	
}


/*
 * This function should return the value of the first item in a priority
 * queue, i.e. the item with LOWEST priority value.
 *
 * Params:
 *   pq - the priority queue from which to fetch a value.  May not be NULL or
 *     empty.
 *
 * Return:
 *   Should return the value of the first item in pq, i.e. the item with
 *   LOWEST priority value.
 */
void* pq_first(struct pq* pq) {
	struct pq_node* k = pq->array->data[0];
	return k->val;
}


/*
 * This function should return the priority value of the first item in a
 * priority queue, i.e. the item with LOWEST priority value.
 *
 * Params:
 *   pq - the priority queue from which to fetch a priority value.  May not be
 *     NULL or empty.
 *
 * Return:
 *   Should return the priority value of the first item in pq, i.e. the item
 *   with LOWEST priority value.
 */
int pq_first_priority(struct pq* pq) {
	struct pq_node* k = pq->array->data[0];
        return k->priority_val;	
}


/*
 * This function should return the value of the first item in a priority
 * queue, i.e. the item with LOWEST priority value, and then remove that item
 * from the queue.
 *
 * Params:
 *   pq - the priority queue from which to remove a value.  May not be NULL or
 *     empty.
 *
 * Return:
 *   Should return the value of the first item in pq, i.e. the item with
 *   LOWEST priority value.
 */
void* pq_remove_first(struct pq* pq) {
	int last = pq->array->size-1;
        struct pq_node* element = pq->array->data[0];
        void* value = element->val;
        if (last != 0){
		free(element);
		struct pq_node* element2 = pq->array->data[last];
		dynarray_set(pq->array,0, element2);
		pq->array->data[last]=NULL;
		pq->array->size--;
                perculate_down(pq, element2, 0);
        }
	else{
		free(element);
		pq->array->size--;
	}
        return value;
}

