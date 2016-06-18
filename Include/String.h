#ifndef STRING_H
#define STRING_H

/**
 * Class implementation
 */
extern String StringClass;

/**
 * Constructors
 */
Any new_String(char*);
Any new_EmptyString();

/**
 * Method implementations
 */
void String_init_impl(Any self, char* init_str);
void String_del_impl(Any self);
Any String_str_impl(Any self);
Any String_copy_impl(Any self);
int String_equals_impl(Any self, Any other);
Any String_add_impl(Any self, Any other);
char* String_toCharArray_impl(Any self);

/**
 * Class layout
 */
struct String {
    ClassProperties properties;

    // Object methods
    void (*init)(Any self, char* init_str);
    void (*del)(Any self);
    Any (*str)(Any self);
    Any (*copy)(Any self);
    int (*equals)(Any self, Any other);
    Any (*add)(Any self, Any other);

    // String methods
    char* (*toCharArray)(Any self);

    // String properties
    char* value;
};

#endif
