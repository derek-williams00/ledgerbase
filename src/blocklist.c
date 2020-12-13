#include "blocklist.h"


/*********************
 *     STRUCTURES    *
 *********************/

struct blocklist {
  struct block* p_block;
  struct blocklist* p_rest;
};


/*********************
 *     FUNCTIONS     *
 *********************/


/*
 * Removes front element from the list.
 */
void blocklist_pop_front(struct blocklist** pp_blocklist) {
  assert(pp_blocklist);
  if(*pp_blocklist == NULL) return;
  struct blocklist* p_blocklist = *pp_blocklist;
  *pp_blocklist = p_blocklist->p_rest;
  free(p_blocklist);
}


void blocklist_push_front(struct blocklist** pp_blocklist, struct block* p_block) {
  assert(pp_blocklist);
  if(*pp_blocklist == NULL) {
    *pp_blocklist = malloc(sizeof(struct blocklist));
    (*pp_blocklist)->p_rest = NULL;
  }

  *pp_blocklist 
}






