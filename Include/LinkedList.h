#ifndef LINKED_LIST_H
#define LINKED_LIST_H

/**
 * Create node
 */
typedef struct Node Node;
struct Node {
    Node* next;
    Node* prev;
    Any value;
};


// LinkedList members
#define LINKED_LIST_MEMBERS \
    LIST_MEMBERS \
    Node* first; \
    Node* last; \
    size_t length;


// LinkedList implementations
#define LINKED_LIST_IMPLS \
    LIST_IMPLS \
    LinkedList_append_impl, \
    LinkedList_remove_impl, \
    LinkedList_removeAt_impl, \
    LinkedList_slice_impl, \
    LinkedList_len_impl, \
    NULL, \
    NULL, \
    0,


// Constructors
LinkedList* new_LinkedList();

// Methods
void LinkedList_init_impl(Any self);
void LinkedList_del_impl(Any self);
String* LinkedList_str_impl(Any self);
Any LinkedList_add_impl(Any self, Any other);
int LinkedList_equals_impl(Any self, Any other);
Any LinkedList_copy_impl(Any self);

void LinkedList_append_impl(Any self, Any obj);
void LinkedList_remove_impl(Any self, Any obj);
void LinkedList_removeAt_impl(Any self, int i);
Any LinkedList_slice_impl(Any self, int start, int end);

size_t LinkedList_len_impl(Any self);

// Initialize string class
LinkedList LinkedListClass;
struct LinkedList { LINKED_LIST_MEMBERS };

#endif
