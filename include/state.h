/*
 * Abstract State Protocol Common Header Implementation.
 */

#ifndef __STATE_H
#define __STATE_H



/*********************
 *     STRUCTURES    *
 *********************/

struct state;

struct state_key;

struct state_context;

struct state_effect;







/*********************
 *     FUNCTIONS     *
 *********************/


struct state* state_copy(const struct state *p_state);
void state_free(const struct state *p_state);


void* state_get_value(const struct state *p_state, void *p_key);


int state_is_valid(const struct state *p_state, const struct state_context *p_context);

/*!! DO LATER:
int state_is_foreign(const struct state *p_state, const struct state_context *p_context);
int state_is_complete(const struct state *p_state, const struct state_context *p_context);
int state_is_partial(const struct state *p_state, const struct state_context *p_context);
!!*/


void state_apply_effect_in_place(struct state *p_state, const struct state_effect *p_effect);
struct state* state_apply_effect(struct state *p_state, const struct state_effect *p_effect);


void state_merge_in_place(struct state *p_place, const struct state *p_other);
struct state* state_merge(const struct state *p_a, const struct state *p_b);







#endif
