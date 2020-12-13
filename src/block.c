#include "block.h"

#include <assert.h> /*!! Make sure this is real */



/*********************
 *     STRUCTURES    *
 *********************/

/*
 * TODO Consider making some of the fields inside block const
 */

/*
 * The genesis block has a block number of 0 and
 * its pointer to the previous block points to NULL.
 *
 * Blocks with a block number greater than 0 may still have
 * a pointer to the previous block that points to NULL if the
 * previous block is unavailable.
 */
struct block {
  /* The index of this block in its blockchain.
   * The genesis has block number 0.
   */
  int number;

  /* The time when this block closed.
   * All timestamped content should occur at or before
   * this timestamp and at or after the timestamp of the previous.
   */
  time_t timestamp;

  /* ID for this block.
   * Generated when the block is created.
   * Freed when the block is freed.
   */
  struct block_id* p_id;

  /* ID for the previous block.
   * Generated when the block is created.
   * Freed when the block is freed.
   * NULL if this block is the Genisis.
   */
  struct block_id*  p_prev_id;

  /* This is the content of this block.
   * This is mostly the responsibility of the clients.
   */
  void* p_content;
};



struct block_id {
  /* The kind of identification. */
  const char* kind;

  /* The length of the digest. */
  int length;

  /* Digest as constant string. */
  const char* digest;
};


/*********************
 *     FUNCTIONS     *
 *********************/


/*
 * CONSTRUCTORS AND DESTRUCTORS
 */

struct block_id* block_id_create() {
  struct block_id* p_block_id = malloc(sizeof(struct block_id));
  p_block_id->kind = NULL;
  p_block_id->length = 0;
  p_block_id->digest = NULL;
  return p_block_id;
}

void block_id_free(struct block_id* p_id) {
  /* NOTE: kind and digest are constant strings so I don't think they
   * need to be freed.
   */
  free(p_id);
}

struct block* block_create(int n, time_t t, void* p_content) {
  p_block->number = n;
  p_block->timestamp = t;
  return p_block;
}

void block_free(struct block* p_block) {
  assert(p_block);
  block_id_free(p_block->p_id);
  block_id_free(p_block->p_prev_id);
}





/*
 * GETTERS
 */

int block_get_n(const struct block* p_block) {
  assert(p_block);
  return p_block->number;
}

time_t block_get_time(const struct block* p_block) {
  assert(p_block);
  return p_block->timestamp;
}

const void* block_get_content(const struct block* p_block) {
  assert(p_block);
  return p_block->p_content;
}

const struct block* block_get_prev(const struct block* p_block) {
  assert(p_block);
  return p_block->p_prev;
}

int block_is_genesis(const struct block* p_block) {
  assert(p_block);
  return p_block->number == 0 && p_block->p_prev == NULL;
}

/*** Requirements for valid blocks ***
 * Previous block must be valid.
 * This block must have a number one greater than the previous.
 * This block must have come at a later time than the previous.
 * The hashes should also make sense but not sure if that'll happen here.
 */
int block_is_valid(const struct block* p_block) {
  const struct block* p_prev = NULL;

  /* Check that block and previous are not NULL pointers. */
  if(!p_block) return 0;
  if(block_is_genesis(p_block)) return 1;
  if(!(p_block->p_prev)) return 0;

  p_prev = p_block->p_prev;

  /* This block must have a number one greater than the previous. */
  if(p_prev->number + 1 != p_block->number) return 0;

  /* This block must have come at a later time than the previous. */
  if(p_prev->timestamp >= p_block->timestamp) return 0;
}





































