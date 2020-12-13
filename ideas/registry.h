/*
 * Data storage and retrieval facilities.
 *
 * Registers records in a data structure that stores constant copies of data and
 * allows ready access by hash-id.
 *
 * const pointers to const data associated with hash identifiers.
 */
#ifndef __REGISTRY_H
#define __REGISTRY_H

/**/
struct registry;



/*
 * Stores a pointer to the data provided.
 *
 * Returns a pointer to the internal pointer.
 */
void** registry_watch(void* data);




/* NOTES
 *
 * Should store data and have facilities to map the hashes to the data.
 * User should provide the hash function and this module should run that hash
 * function over the data to check that the hash value provided is correct.
 *
 * An associative array maps the hash digest identifier to the pointer and vice-versa.
 * When the user requests the data by hash digest identifier, the module should check that the
 * digest function still works.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */





















#endif
