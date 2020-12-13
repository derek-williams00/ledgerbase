#include "ledger.h"


int main() {

  struct ledger_charter* p_charter = ledger_charter_create( /*TODO*/
  struct ledger_state* p_initial_state = /*TODO*/
  struct ledger_basis* p_basis = ledger_basis_create(p_charter, p_inital_state);
  struct ledger* p_ledger = ledger_create();




  ledger_free(p_ledger);
  return 0;
}


