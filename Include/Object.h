#ifndef OBJECT_H
#define OBJECT_H


// Object members
#define OBJECT_MEMBERS \
    Method init; \
    Method del; \
    Method str; \
    Method add;


// Object implementations
#define OBJECT_IMPLS \
    Object_init_impl, \
    Object_del_impl, \
    Object_str_impl, \
    Object_add_impl,

// Constructors
Object* new_Object();

// Methods
void Object_init_impl(Any self);
void Object_del_impl(Any self);

String* Object_str_impl(Any self);
#define STR(obj) CALL(String*, (Any), CAST(Object, obj), str)

Any Object_add_impl(Any self, Any other);
#define ADD(obj, other) CALL(Any, (Any, Any), CAST(Object, obj), add, other)


Object ObjectClass;
struct Object { OBJECT_MEMBERS };


#endif
