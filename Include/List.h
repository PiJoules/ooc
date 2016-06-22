#ifndef LIST_H
#define LIST_H

// List members
#define LIST_MEMBERS \
    OBJECT_MEMBERS \
    Method append; \
    Method remove; \
    Method removeAt; \
    Method slice; \
    Method len; \
    Method get; \
    Method clear;


// List implementations
#define LIST_IMPLS \
    OBJECT_IMPLS

// Methods
#define APPEND(lst, obj) CALL(void, (Any, Any), CAST(List, lst), append, obj)
#define REMOVE(lst, obj) CALL(void, (Any, Any), CAST(List, lst), remove, obj)
#define REMOVE_AT(lst, i) CALL(void, (Any, int), CAST(List, lst), removeAt, i)
#define SLICE(lst, start, end) CALL(Any, (Any, int, int), CAST(List, lst), slice, start, end)
#define LEN(lst) CALL(size_t, (Any), CAST(List, lst), len)
#define GET(lst, i) CALL(Any, (Any, int i), CAST(List, lst), get, i)
#define CLEAR(lst) CALL(void, (Any), CAST(List, lst), clear)

// Initialize string class
struct List { LIST_MEMBERS };

#endif
