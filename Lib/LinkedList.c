#include "All.h"

// Initialize string class
List ListClass = {
    &ListClass,
    LIST_IMPLS
};

// Apply method overrides
static void List_overrides(List* self){
    self->init = List_init_impl;
    self->del = List_del_impl;
    self->str = List_str_impl;
    self->add = List_add_impl;
    self->equals = List_equals_impl;
    self->copy = List_copy_impl;
}

// Constructors
List* new_LinkedList(){
    CREATE(List);
    APPLY_OVERRIDES(List);
    CALL(void, (Any), obj, init);
    return obj;
}


// Implementations
void List_init_impl(Any self){
    SUPER_CALL(void, (Any), Object, init);
}

void List_del_impl(Any self){
}

String* List_str_impl(Any self){
    return new_EmptyString();
}

Any List_add_impl(Any self, Any other){
    return new_LinkedList();
}

int List_equals_impl(Any self, Any other){
    if (CLASS(self) != CLASS(other)){
        return 0;
    }
    return 1;
}

Any List_copy_impl(Any self){
    return new_LinkedList();
}


void List_append_impl(Any self, Any obj){}

void List_remove_impl(Any self, Any obj){}

void List_removeAt_impl(Any self, int i){}

Any List_slice_impl(Any self, int start, int end){
    return new_LinkedList();
}

size_t List_len_impl(Any self){
    return 0;
}
