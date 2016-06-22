#ifndef LIST_H
#define LIST_H

// List members
#define LIST_MEMBERS \
    OBJECT_MEMBERS \
    Method append; \
    Method remove; \
    Method removeAt; \
    Method slice; \
    Method len;


// List implementations
#define LIST_IMPLS \
    OBJECT_IMPLS \
    List_append_impl, \
    List_remove_impl, \
    List_removeAt_impl, \
    List_slice_impl, \
    List_len_impl


// Constructors
List* new_LinkedList();

// Methods
void List_init_impl(Any self);
void List_del_impl(Any self);
String* List_str_impl(Any self);
Any List_add_impl(Any self, Any other);
int List_equals_impl(Any self, Any other);
Any List_copy_impl(Any self);

void List_append_impl(Any self, Any obj);
#define APPEND(lst, obj) CALL(void, (Any, Any), CAST(List, lst), append, obj)

void List_remove_impl(Any self, Any obj);
#define REMOVE(lst, obj) CALL(void, (Any, Any), CAST(List, lst), remove, obj)

void List_removeAt_impl(Any self, int i);
#define REMOVE_AT(lst, i) CALL(void, (Any, int), CAST(List, lst), removeAt, i)

Any List_slice_impl(Any self, int start, int end);
#define SLICE(lst, start, end) CALL(Any, (Any, int, int), CAST(List, lst), slice, start, end)

size_t List_len_impl(Any self);
#define LEN(lst) CALL(size_t, (Any), CAST(List, lst), len)

// Initialize string class
List ListClass;
struct List { LIST_MEMBERS };

#endif
