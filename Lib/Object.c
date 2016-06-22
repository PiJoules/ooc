#include "All.h"

// Initialize the object class
Object ObjectClass = {
    &ObjectClass,
    OBJECT_IMPLS
};

// Constructors
Object* new_Object(){
    CREATE(Object);
    CALL(void, (Any), obj, init);
    return obj;
}

// Implementations
void Object_init_impl(Any self){}
void Object_del_impl(Any self){}

String* Object_str_impl(Any self){
    char* str = formattedString("<object Object at %p>", self);
    String* str_obj = new_String(str);
    free(str);
    return str_obj;
}

Any Object_add_impl(Any self, Any other){
    return new_Object();
}

int Object_equals_impl(Any self, Any other){
    return CLASS(self) == CLASS(other);
}

// Deep copy
Any Object_copy_impl(Any self){
    return new_Object();
}

