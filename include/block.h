/*
 *
 *
 *
 *
 */


#ifndef __BLOCKCHAIN_BLOCK_H
#define __BLOCKCHAIN_BLOCK_H


#include <stdlib.h>
#include <time.h>


/*********************
 *     STRUCTURES    *
 *********************/

struct block;

struct block_id;


/*********************
 *     FUNCTIONS     *
 *********************/

/*
 * CONSTRUCTORS AND DESTRUCTORS
 */

struct block* block_create(int n, time_t t, void* p_content);
void block_free(struct block* p_block);

struct block_id* block_id_create();
void block_id_free(struct block_id* p_id);

/*
 * ACCESSORS
 */

int block_get_n(const struct block* p_block);
time_t block_get_time(const struct block* p_block);
const struct block_id* block_get_id(const struct block* p_block);
const struct block_id* block_get_prev_id(const struct block* p_block);
const void* block_get_content(const struct block* p_block);

int block_is_genesis(const struct block* p_block);

/*** Requirements for valid blocks ***
 * Previous block must be valid.
 * This block must have a number one greater than the previous.
 * This block must have come at a later time than the previous.
 */
int block_is_valid(const struct block* p_block);

/*
 * MUTATORS
 */



#endif
