#ifndef STRING_H
#define STRING_H

// String members
#define STRING_MEMBERS \
    OBJECT_MEMBERS \
    Method toCharArray; \
    char* value;


// String implementations
#define STRING_IMPLS \
    OBJECT_IMPLS \
    String_toCharArray_impl, \
    NULL,


// Constructors
String* new_String(char* value);
String* new_EmptyString();

// Methods
void String_init_impl(Any self, char* value);
void String_del_impl(Any self);
String* String_str_impl(Any self);
char* String_toCharArray_impl(Any self);
Any String_add_impl(Any self, Any other);

// Initialize string class
String StringClass;
struct String { STRING_MEMBERS };

#endif
