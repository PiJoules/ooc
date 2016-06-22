#include "All.h"


// Initialize string class
LinkedList LinkedListClass = {
    &LinkedListClass,
    LINKED_LIST_IMPLS
};

// Apply method overrides
static void LinkedList_overrides(LinkedList* self){
    self->init = LinkedList_init_impl;
    self->del = LinkedList_del_impl;
    self->str = LinkedList_str_impl;
    self->add = LinkedList_add_impl;
    self->equals = LinkedList_equals_impl;
    self->copy = LinkedList_copy_impl;
}




// Constructors
LinkedList* new_LinkedList(){
    CREATE(LinkedList);
    APPLY_OVERRIDES(LinkedList);
    CALL(void, (Any), obj, init);
    return obj;
}


// Implementations
void LinkedList_init_impl(Any self){
    SUPER_CALL(void, (Any), Object, init);
}

void LinkedList_del_impl(Any self){
    LinkedList* lst = SELF(LinkedList);
    
    for (Node* current = lst->first; current != NULL; current = current->next){
        if (current->prev){
            // Do not destory the value.
            // The programmer is in charge of that.
            free(current->prev);
        }
    }

    free(lst->last);
}

String* LinkedList_str_impl(Any self){
    return new_EmptyString();
}

Any LinkedList_add_impl(Any self, Any other){
    return new_LinkedList();
}

int LinkedList_equals_impl(Any self, Any other){
    if (CLASS(self) != CLASS(other)){
        return 0;
    }
    return 1;
}

Any LinkedList_copy_impl(Any self){
    return new_LinkedList();
}


void LinkedList_append_impl(Any self, Any obj){
    LinkedList* list = SELF(LinkedList);
    Node* node = malloc(sizeof(Node));

#ifdef DEBUG
    assert(node);
#endif

    node->value = obj;
    node->next = node->prev = NULL;

    if (list->last == NULL) {
        // Empty list
#ifdef DEBUG
        assert(list->length == 0);
#endif

        list->first = list->last = node;
    }
    else {
#ifdef DEBUG
        assert(list->length > 0);
#endif

        list->last->next = node;
        node->prev = list->last;
        list->last = node;
    }

    list->length++;
}

void LinkedList_remove_impl(Any self, Any obj){
    LinkedList* list = SELF(LinkedList);
    //void *result = NULL;

#ifdef DEBUG
    assert(list->first && list->last);
    assert(list->length > 0);
    assert(obj);
#endif

    for (Node* current = list->first; current != NULL; current = current->next){
        Any value = current->value;
        if (EQUALS(value, obj)){
            Node* prevNode = current->prev;
            Node* nextNode = current->next;
            if (prevNode){
                prevNode->next = nextNode;
            }
            if (nextNode){
                nextNode->prev = prevNode;
            }

            if (current == list->first){
                list->first = nextNode;
            }
            if (current == list->last){
                list->last = prevNode;
            }

            free(current);

            list->length--;
            return;
        }
    }

    // Did not find element to remove
    exit(1);
}

void LinkedList_removeAt_impl(Any self, int i){}

Any LinkedList_slice_impl(Any self, int start, int end){
    return new_LinkedList();
}

size_t LinkedList_len_impl(Any self){
    return SELF(LinkedList)->length;
}
