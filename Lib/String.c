#include "All.h"

/**
 * Class implementation
 */
String StringClass = {
    {
        sizeof(String),
        &StringClass,
        &ObjectClass,
    },

    // Object methods
    String_init_impl,
    String_del_impl,
    String_str_impl,
    String_copy_impl,
    String_equals_impl,
    String_add_impl,

    // String methods
    String_toCharArray_impl,

    // String properties
    "",
};


/**
 * Constructors
 */
Any new_String(char* init_str){
    String* obj = (String*)new(&StringClass);
    obj->init(obj, init_str);
    return obj;
}

Any new_EmptyString(){
    return new_String("");
}


/**
 * Method implementations
 */
void String_init_impl(Any self, char* init_str){
    SUPER(Object, init);

    size_t size = sizeof(char) * (strlen(init_str) + 1);
    SELF(String)->value = (char*)malloc(size);
    memcpy(SELF(String)->value, init_str, size);
}

void String_del_impl(Any self){
    SUPER(Object, del);
    free(SELF(String)->value);
}

Any String_str_impl(Any self){
    return SELF(String)->copy(self);
}

Any String_copy_impl(Any self){
    return new_String(SELF(String)->value);
}

Any String_add_impl(Any self, Any other){
    String* s = SELF(String);
    String* o = CAST(String, other);

    size_t self_size = strlen(s->value);
    size_t other_size = strlen(o->value);
    char* result = (char*)malloc(self_size + other_size + 1);

#ifdef DEBUG
    assert(result);
#endif

    strncpy(result, s->value, self_size);

    /**
     * Valgrind returns:
     * "Conditional jump or move depends on uninitialised value(s)"
     * if the result does not have a null terminator at the end of the inistal string.
     *
     * This error is not thrown (or necessary) by gcc, but valgrind doesn't like it.
     */
    result[self_size] = '\0';

    strncat(result, o->value, other_size);
    result[self_size + other_size] = '\0';

    Any result_obj = new_String(result);
    free(result);
    return result_obj;
}

int String_equals_impl(Any self, Any other){
    if (SELF_TYPE != TYPE(other)){
        return 0;
    }

    String* s = SELF(String);
    String* o = CAST(String, other);

    size_t self_size = strlen(s->value);
    size_t other_size = strlen(o->value);

    if (self_size != other_size){
        return 0;
    }

    return !strncmp(s->value, o->value, self_size);
}

char* String_toCharArray_impl(Any self){
    return SELF(String)->value;
}
