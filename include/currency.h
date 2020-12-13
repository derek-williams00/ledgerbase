#ifndef __CURRENCY_H
#define __CURRENCY_H



struct current_account;

int current_account_n_debits(const struct current_account* p_current_account);
int current_account_n_credits(const struct current_account* p_current_account);
int current_account_balance(const struct current_account* p_current_account);



struct payment;

const char* payment_unit(const struct payment* p_payment);
int payment_amount(const struct payment* p_payment);
const struct current_account* payment_payer(const struct payment* p_payment)
const struct current_account* payment_payee(const struct payment* p_payment)



/*
 * Payments correspond to a debit in one account and a credit in another.
 */

/* IDEA:
 *
 * Payments with intermidiaries. Ledgers could have a toll or boost to
 * encourage or discourage payments as an intermidiate with other ledgers.
 *
 */







#endif
