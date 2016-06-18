#include "All.h"

/**
 * Class implementation
 */
const Object ObjectClass = {
    {
        sizeof(Object),
        (Any) &ObjectClass,
        NULL,
    },

    // Object methods
    Object_init_impl,
    Object_del_impl,
    Object_str_impl,
    Object_copy_impl,
    Object_equals_impl,
    Object_add_impl,
};


/**
 * Constructors
 */
Any new_Object(){
    Object* obj = NEW(Object);
    obj->init(obj);
    return obj;
}

/**
 * Method implementations
 */
void Object_init_impl(Any self){}

void Object_del_impl(Any self){}

Any Object_str_impl(Any self){
    return new_EmptyString();
}

Any Object_copy_impl(Any self){
    return new_Object();
}

int Object_equals_impl(Any self, Any other){
    return SELF_TYPE == TYPE(other);
}

Any Object_add_impl(Any self, Any other){
    return new_Object();
}
