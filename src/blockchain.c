#include "blockchain.h"

#include <assert.h> /*!! Make sure this is real */



/*********************
 *     STRUCTURES    *
 *********************/


/*
 * The genesis block has a block number of 0 and
 * its pointer to the previous block points to NULL.
 *
 * Blocks with a block number greater than 0 may still have
 * a pointer to the previous block that points to NULL if the
 * previous block is unavailable.
 */
struct block {
  int block_n;
  time_t timestamp;
  void* p_content;
  struct block* p_prev;
};

struct blocklist {
  struct block* p_block;
  struct blocklist* p_rest;
};

struct blocktree {
  struct block* p_block;
  int n_children;
  int n_descendants;
  struct blocktree** p_children;
};

struct blockchain {
  struct blocktree* p_blocktree;
};




/*********************
 *     FUNCTIONS     *
 *********************/

/*
 * GETTERS
 */

const struct block* blockchain_get_genisis(const struct blockchain* p_blockchain) {
  assert(p_blockchain);
  return p_blockchain->p_genesis;
}

const struct block* block_get_prev(const struct block* p_block) {
  assert(p_block);
  return p_block->p_prev;
}


void* block_get_content(const struct block* p_block) {
  assert(p_block);
  return p_block->p_content;
}

time_t block_get_time(const struct block* p_block) {
  assert(p_block);
  return p_block->timestamp;
}


/*
 * CONSTRUCTORS & DESTRUCTORS
 */

struct block* block_create(int block_n, time_t timestamp, void* p_content, struct block* p_prev) {
  struct block* p_block = malloc(sizeof(struct block));
  p_block->block_n = block_n;
  p_block->timestamp = timestamp;
  p_block->p_content = p_content;
  p_block->p_prev = p_prev;
  return p_block;
}

void block_free(struct block* p_block) {
  free(p_block);
}


struct blocklist* blocklist_create() {
  struct blocklist* p_blocklist = malloc(sizeof(struct blocklist));
  /* TODO */
}

void blocklist_free(struct blocklist* p_blocklist) {
  /* TODO */
}

struct blocktree* blocktree_create(struct block* p_block, int n_children, struct blocktree** p_children) {
  struct blocktree* p_blocktree = malloc(sizeof(struct blocktree));
  p_blocktree->p_block = p_block;
  p_blocktree->n_children = n_children;
  p_blocktree->p_children = p_children;
  return p_blocktree;
}

struct blocktree* blocktree_create() {
  struct block* p_block = NULL;
  int n_children = 0;
  struct blocktree** p_children = NULL;
  return blocktree_create(p_block, n_children, p_children);
}

/*
 * Free tree and subtrees but does not free blocks.
 */
void blocktree_free(struct blocktree* p_blocktree) {
  int i;
  if(p_blocktree) {
    if(p_blocktree->p_children) {
      for(i=0; i < p_blocktree->n_children; ++i) {
        blocktree_free(p_blocktree->p_children[i]);
      }
      free(p_children);
    }
    free(p_blocktree);
  }
}

struct blockchain* blockchain_create() {
  struct blockchain* p_blockchain = malloc(sizeof(struct blockchain));
  p_blockchain->p_blocktree = blocktree_create();
  /* TODO */
}

void blocktree_free(struct blockchain* p_blockchain) {
  assert(p_blockchain);
  p_blockchain->p_blocktree = blocktree_create();
}



int blockchain_accept(struct blockchain* p_blockchain, struct block* p_block) {
  /* TODO */
  assert(p_block);
  assert(p_blockchain);
  assert(p_blockchain->p_blocktree);

  /* Trace down the blocktree to the layer for the block with this number */
}








