/*
 *
 * The implementation should check that the block traces back to genisis and other stuff.
 *
 */

#ifndef __BLOCKCHAIN_H
#define __BLOCKCHAIN_H



/*********************
 *     STRUCTURES    *
 *********************/


struct blockchain;

struct block;




/*********************
 *     FUNCTIONS     *
 *********************/



const struct block* blockchain_get_genisis(const struct blockchain* p_blockchain);


const struct block* blockchain_get_tip(
  const struct blockchain* p_blockchain,

  /* This function compares two blocks to see which is better.
   * This function can return NULL if neither block is valid.
   */
  const struct block* (*best)(const struct block* p_a, const struct block* p_b)
);


const struct block* block_get_prev(const struct block* p_block);
void* block_get_content(const struct block* p_block);





#endif
