#ifndef LIST_H
#define LIST_H

/**
 * Class implementation
 */
extern const List ListClass;

/**
 * Constructors
 */
Any new_List();

/**
 * Method implementations
 */
void List_init_impl(Any self);
void List_del_impl(Any self);
Any List_str_impl(Any self);
Any List_copy_impl(Any self);
int List_equals_impl(Any self, Any other);
Any List_add_impl(Any self, Any other);

void List_append_impl(Any self, Any obj);
void List_remove_impl(Any self, Any obj);
void List_removeAt_impl(Any self, int i);
Any List_slice_impl(Any self, int start, int end);

/**
 * Class layout
 */
struct List {
    ClassProperties properties;

    // Object methods
    void (*init)(Any self);
    void (*del)(Any self);
    Any (*str)(Any self);
    Any (*copy)(Any self);
    int (*equals)(Any self, Any other);
    Any (*add)(Any self, Any other);

    // List methods
    void (*append)(Any self, Any obj);
    void (*remove)(Any self, Any obj);
    void (*removeAt)(Any self, int i);
    Any (*slice)(Any self, int start, int end);
};

#endif
