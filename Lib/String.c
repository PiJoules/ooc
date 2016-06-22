#include "All.h"

// Initialize string class
INITIALIZE_CLASS(String, STRING_IMPLS)

// Apply method overrides
static void String_overrides(String* self){
    self->init = String_init_impl;
    self->del = String_del_impl;
    self->str = String_str_impl;
    self->add = String_add_impl;
    self->equals = String_equals_impl;
    self->copy = String_copy_impl;
}


// Constructors
String* new_String(char* value){
    CREATE(String);
    CALL(void, (Any, char*), obj, init, value);
    return obj;
}

String* new_EmptyString(){
    return new_String("");
}


// Implementations
void String_init_impl(Any self, char* value){
    SUPER_CALL(void, (Any), Object, init);

    String* self_str = (String*) self;
    const size_t str_size = sizeof(char) * strlen(value);
    self_str->value = (char*)malloc(str_size + 1);

#ifdef DEBUG
    assert(self_str->value);
#endif

    copyStrInplace(self_str->value, value, str_size);
}

void String_del_impl(Any self){
    free(SELF(String)->value);
}

String* String_str_impl(Any self){
    return new_String(SELF(String)->value);
}

char* String_toCharArray_impl(Any self){
    return SELF(String)->value;
}

Any String_add_impl(Any self, Any other){
    String* self_str = SELF(String);
    String* other_str = CAST(String, other);
    const size_t self_size = sizeof(char) * strlen(self_str->value);
    const size_t other_size = sizeof(char) * strlen(other_str->value);
    char* result = (char*)malloc(self_size + other_size + 1);

#ifdef DEBUG
    assert(result);
#endif

    strncpy(result, self_str->value, self_size);
    result[self_size] = '\0';

    strncat(result, other_str->value, other_size);
    result[self_size + other_size] = '\0';

    Any result_obj = new_String(result);
    free(result);
    return result_obj;
}

int String_equals_impl(Any self, Any other){
    if (CLASS(self) != CLASS(other)){
        return 0;
    }

    String* s = SELF(String);
    String* o = CAST(String, other);

    const size_t self_size = strlen(s->value);
    const size_t other_size = strlen(o->value);

    if (self_size != other_size){
        return 0;
    }

    return !strncmp(s->value, o->value, self_size);
}

Any String_copy_impl(Any self){
    return new_String(SELF(String)->value);
}


