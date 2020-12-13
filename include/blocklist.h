/*
 *
 *
 *
 *
 */


#ifndef __BLOCKLIST_H
#define __BLOCKLIST_H


#include <stdlib.h>


/*********************
 *     STRUCTURES    *
 *********************/

/* List of blocks */
struct blocklist;



/*********************
 *     FUNCTIONS     *
 *********************/

/*
 * GETTERS
 */






/*
 * MUTATORS
 */

/*
 * Removes front element from the list.
 */
void blocklist_pop_front(struct blocklist** pp_blocklist);
void blocklist_push_front(struct blocklist** pp_blocklist, struct block* p_block);




#endif
