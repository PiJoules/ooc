#ifndef OBJECT_H
#define OBJECT_H

/**
 * Class implementation
 */
extern Object ObjectClass;

/**
 * Constructors
 */
Any new_Object();

/**
 * Method implementations
 */
void Object_init_impl(Any self);
void Object_del_impl(Any self);
Any Object_str_impl(Any self);
Any Object_copy_impl(Any self);
int Object_equals_impl(Any self, Any other);
Any Object_add_impl(Any self, Any other);

/**
 * Class layout
 */
struct Object {
    ClassProperties properties;

    // Object methods
    void (*init)(Any self);
    void (*del)(Any self);
    Any (*str)(Any self);
    Any (*copy)(Any self);
    int (*equals)(Any self, Any other);
    Any (*add)(Any self, Any other);
};

#endif
