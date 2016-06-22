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
    LinkedList_get_impl, \
    LinkedList_clear_impl, \
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
Any LinkedList_get_impl(Any self, int i);
size_t LinkedList_len_impl(Any self);
void LinkedList_clear_impl(Any self);

#define ITERATE(list, obj) \
    LinkedList* tmpList_ = CAST(LinkedList, list); \
    Node* iterator_ = tmpList_->first; \
    Any obj = iterator_ ? iterator_->value : NULL; \
    for (; iterator_; iterator_ = iterator_->next, obj = iterator_ ? iterator_->value : NULL)

#define ENUMERATE(list, obj, i_) \
    LinkedList* tmpList_ = CAST(LinkedList, list); \
    Node* iterator_ = tmpList_->first; \
    size_t i_; \
    Any obj = iterator_ ? iterator_->value : NULL; \
    for (; iterator_ && i_ < tmpList_->length; i_++, iterator_ = iterator_->next)

// Initialize string class
LinkedList LinkedListClass;
struct LinkedList { LINKED_LIST_MEMBERS };

#endif
