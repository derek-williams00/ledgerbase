/*
 * This header declares the blockchain and block structs and
 * the operations that may be performed on them.
 *
 * The implementation should check that the block traces back to genisis and other stuff.
 *
 */

#ifndef __BLOCKCHAIN_H
#define __BLOCKCHAIN_H

#include <stdlib.h>

/* This is used for the time_t type. */
#include <time.h>


/*********************
 *     STRUCTURES    *
 *********************/

/* Stores the number, timestamp, pointer to content, and pointers to content and previous block. */
struct block;

/* List of blocks */
struct blocklist;

/* Tree of blocks */
struct blocktree;

/* Maps anything to blocks */
struct blockmap;

/* Maps constant strings to blocks */
struct blocktable;

/* Maps hash functions and hash digests of blocks to blocks */
struct blockspace;

struct blockchain;



/*********************
 *     FUNCTIONS     *
 *********************/

/*
 * GETTERS
 */

const struct block* blockchain_get_genisis(const struct blockchain* p_blockchain);

void* blockchain_create_genesis_state(const struct blockchain* p_blockchain);

const struct block* block_get_prev(const struct block* p_block);

const void* block_get_content(const struct block* p_block);

const void* block_get_state(
  const struct block* p_block,
  void (*integrator)(const struct block* p_block, void* p_prev_state)
);

time_t block_get_time(const struct block* p_block);

int block_get_n(const struct block* p_block);


/*
 * CONSTRUCTORS & DESTRUCTORS
 */

struct block* block_create(int block_n, time_t timestamp, void* p_content, struct block* p_prev);
void block_free(struct block* p_block);

struct blocklist* blocklist_create();
void blocklist_free(struct blocklist* p_blocklist);

struct blocktree* blocktree_create();
struct blocktree* blocktree_create(struct block* p_block, int n_children, struct blocktree** p_children);
void blocktree_free(struct blocktree* p_blocktree);

struct blockchain* blockchain_create();
void blocktree_free(struct blockchain* p_blockchain);


/*
 * Mutators
 */

void blocklist_push_front(struct blocklist* p_blocklist, struct block* p_block);
void blocklist_push_back(struct blocklist* p_blocklist, struct block* p_block);

void blocktree_nest(struct blocktree* p_supertree, struct blocktree* p_subtree);
void blocktree_prune(struct blocktree* p_blocktree, int (*keep_child_tree)(struct blocktree* p_child_tree));
struct blocktree* blocktree_select_subtree(struct blocktree* p_blocktree, int (*selector)(struct blocktree* p_subtree));

int blockchain_accept(struct blockchain* p_blockchain, struct block* p_block);













#endif
