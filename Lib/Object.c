#include "All.h"

/**
 * Class implementation
 */
Object ObjectClass = {
    {
        sizeof(Object),
        &ObjectClass,
        NULL,
    },

    // Object implementations
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
    Object* obj = (Object*)new(&ObjectClass);
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
    Object* obj = SELF(Object);
    Object* obj_copy = (Object*)malloc(obj->properties.size);

#ifdef DEBUG
    assert(obj_copy);
#endif

    memcpy(obj_copy, obj, obj->properties.size);
    return obj_copy;
}

int Object_equals_impl(Any self, Any other){
    return SELF_TYPE == TYPE(other);
}

Any Object_add_impl(Any self, Any other){
    return new_Object();
}
