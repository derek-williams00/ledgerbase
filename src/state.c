#include "state.h"



/*********************
 *     STRUCTURES    *
 *********************/

struct state {
  /* TODO */
};

struct state_key {
  /* TODO */
};

struct state_context {
  /* TODO */
};

struct state_effect {
  /* TODO */
};





/*********************
 *     FUNCTIONS     *
 *********************/


struct state* state_copy(const struct state *p_state);
void state_free(const struct state *p_state);


void* state_get_value(const struct state *p_state, void *p_key);


int state_is_valid(const struct state *p_state, const struct state_context *p_context);


void state_apply_effect_in_place(struct state *p_state, const struct state_effect *p_effect);
struct state* state_apply_effect(struct state *p_state, const struct state_effect *p_effect);


void state_merge_in_place(struct state *p_place, const struct state *p_other);
struct state* state_merge(const struct state *p_a, const struct state *p_b);







