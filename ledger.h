#ifndef __LEDGER_H
#define __LEDGER_H


/*
 * Non-transportable
 */
struct ledger;

/*
 * Original constants of a ledger.
 *
 * Used to generate the ledger's id.
 */
struct ledger_basis;

/*
 * Corresponds to a unique ledger identity.
 */
struct ledger_id;

/*
 * Describes the history of a ledger during a particular
 * period of time.
 */
struct ledger_chapter;

/**/
struct ledger_state;

/*
 * Determines how a TODO
 *
 * Part of the ledger's state or part of the ledger's basis.
 */
struct ledger_charter;


/* NOTES:
 *
 * basis ( charter , initial_state )
 * ledger ( basis )
 *
 *
 *
 */




struct ledger_charter* ledger_charter_create(
  int n_ins,
  const char* ins,
  void (charter_builder*)(struct ledger_charter* p_charter, int n_ins, const char* ins)
);

struct ledger_basis* ledger_basis_create(
  const struct ledger_charter* p_charter,
  const struct ledger_state* p_initial_state,
);


struct ledger* ledger_create(const struct ledger_basis* p_basis);
void ledger_free(struct ledger* p_ledger);

struct ledger_id* ledger_get_id(const struct ledger_basis* p_basis);





/*
 * Get chapter from ledger.
 *
 * Can return NULL
 */
const struct ledger_chapter* ledger_get_chapter(int n);


struct ledger_id* ledger_id_create(const struct ledger_basis* p_basis);

void ledger_id_free(struct ledger_id* p_ledger_id);

int equal_ledger_ids(const struct ledger_id* p_a, const struct ledger_id* p_b);




/**/
int chapter_get_n(const struct ledger_chapter* p_chapter);

/**/
const struct ledger_id* chapter_get_ledger_id(const struct ledger_chapter* p_chapter);

/*
 * Pointer to previous chapter.
 * NULL if first chapter.
 */
const struct ledger_chapter* chapter_get_prev(const struct ledger_chapter* p_chapter);

/*
 * The duration of time that this chapter covers in nanoseconds.
 */
int chapter_get_span(const struct ledger_chapter* p_chapter);

struct ledger_state* ledger_initial_state(const struct ledger* p_ledger);

struct ledger_state* chapter_suppose(const struct ledger_chapter* p_chapter);



struct ledger_state* ledger_initial_state(const struct ledger_basis* p_basis);

struct ledger_charter* basis_get_charter(const struct ledger_basis* p_basis);




#endif
