#ifndef __LEDGER_H
#define __LEDGER_H


struct ledger;

struct ledger* ledger_create();
void ledger_free(struct ledger* p_ledger);




struct charter;
struct event;

struct charter* charter_create(int n_ins, char* ins);
void charter_free(struct charter* p_charter)




/*
 * This is a collection of events that are bound into chapters.
 *
 * They document the changes to a ledger that occur over time.
 *
 * New chapters can be checked into a history but they may not hold.
 *
 */
struct history;

struct history* history_create();
void history_free(struct history* p_history);


/*
 * The history of a ledger is made of chapters which bind a particular span of time
 * and list all of the events that occur within this ledgers domain over that period.
 * A chapter may or may not be cannon.
 */
struct chapter;

struct chapter* chapter_create();
void chapter_free(struct chapter* p_chapter);
struct chapter* chapter_create(int n_events, struct event* events);


/*
 * This should return 0 if it is not valid.
 */
int check(struct history* p_history, struct chapter* p_chapter);

struct chapter* get_chapter(struct history* p_history, int chapter_n);





/*
 * The registry is a construct of a ledger's state.
 * It is like the database of a ledger.
 * It's entries are mutable and therefore their state is a function of time.
 */
struct registry;

/*
 * An entry holds data in a registry.
 */
struct entry;


const struct entry* get_entry(struct registry* registry, int (*identify)(const struct entry* entry));


/*
 * A cause determines how an event should effect the registry.
 */
struct cause;

/*
 * This corresponds to a change in the registry.
 */
struct effect;

/*
 * An effect is created from a cause which describes the way in which the effect should be created,
 * and an event that actually produced the effect.
 *
 * If you don't like the way I named stuff then let me know and let it go.
 */
struct effect* effect_create(struct cause* cause, struct event* event);


/*
 * This shows all of the effects that lead up to a particular state.
 *
 * A brief contains less data than a history but can still generate ledger state.
 */
struct brief;


/*
 * This is the state of a ledger at some point in its history.
 * The state could be very recent or even "current" (its almost always ok to be a little behind)
 *
 * A state can be generated from a brief or a history.
 */
struct state;

struct state* state_create(struct history* p_history, int chapter_n);
struct state* state_create(struct brief* brief);










#endif
