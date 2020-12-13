#include "ledger.h"


/*********************
 *     STRUCTURES    *
 *********************/





/**/
struct ledger_basis {
  struct ledger_charter* p_original_charter;
  struct ledger_state* p_initial_state;
};



/**/
struct ledger_chapter {
  struct ledger_chapter* p_prev;
  struct ledger_id* p_id;
  int n_entries;
  void* entries;
};






/*********************
 *     FUNCTIONS     *
 *********************/



/**/
struct ledger_charter* ledger_charter_create(
  int n_ins, const char* ins,
  int (*builder)(struct ledger_charter* p_charter, int n_ins, const char* ins)
) {
  struct ledger_charter* p_charter = malloc(sizeof(struct ledger_charter));
  int d;
  int n_ins_left = n_ins;
  const char* cur_ins = ins;
  while(n_ins_left > 0) {
    d = builder(p_charter, n_ins_left, cur_ins);
    n_ins_left -= d;
    cur_ins += d;
  }
  return p_charter;
}




