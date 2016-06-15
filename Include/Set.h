#ifndef SET_H
#define SET_H

extern const void* Set;

/**
 * Adds element.
 * Returns whatever was added or already exists in set.
 */
void* add(void* set, const void* element);

/**
 * Finds element.
 * Returns whatever is found in the set or a null pointer.
 */
void* find(void* set, const void* element);

/**
 * Remove element.
 * Locates element in set.Returns whatever is removed from the set.
 * Use drop() since remove() is already taken by stdio.
 */
void* drop(void* set, const void* element);

/**
 * Check if an item is in the set.
 */
int contains(void* set, const void* element);

#endif
