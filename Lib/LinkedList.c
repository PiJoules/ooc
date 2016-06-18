#include "All.h"

/**
 * Class implementation
 */
const List ListClass = {
    {
        sizeof(List),
        (Any) &ListClass,
        (Any) &ObjectClass,
    },

    // Object methods
    List_init_impl,
    List_del_impl,
    List_str_impl,
    List_copy_impl,
    List_equals_impl,
    List_add_impl,

    // List methods
    List_append_impl,
    List_remove_impl,
    List_removeAt_impl,
    List_slice_impl,
};


/**
 * Constructors
 */
Any new_List(){
    List* obj = NEW(List);
    obj->init(obj);
    return obj;
}

/**
 * Method implementations
 */
void List_init_impl(Any self){}

void List_del_impl(Any self){}

Any List_str_impl(Any self){
    return new_EmptyString();
}

Any List_copy_impl(Any self){
    return new_List();
}

int List_equals_impl(Any self, Any other){
    return SELF_TYPE == TYPE(other);
}

Any List_add_impl(Any self, Any other){
    return new_List();
}
