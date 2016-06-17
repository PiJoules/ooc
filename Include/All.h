#ifndef ALL_H
#define ALL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>
#include <string.h>

/**
 * Typedef struct declarations
 */
typedef void* AnyClass;
typedef struct _ObjectClass ObjectClass;
typedef struct _StringClass StringClass;

ObjectClass Object;
StringClass String;

void Object___init___impl(AnyClass self, ...);
void Object___del___impl(AnyClass self);
StringClass* Object___repr___impl(AnyClass self);
StringClass* Object___str___impl(AnyClass self);

void String___init___impl(AnyClass self, ...);
void String___del___impl(AnyClass self);
char* String_toCharArray_impl(AnyClass self);

typedef struct {
    const size_t size;
    const AnyClass parent;
} ClassProperties;


/**
 * Macros
 */
#define SUPER(parent_class, method, ...) ((parent_class*)(super(self)))->method(self, ##__VA_ARGS__)

#define OBJECT_MEMBERS \
    void (*__init__)(AnyClass self, ...); \
    void (*__del__)(AnyClass self); \
    StringClass* (*__repr__)(AnyClass self); \
    StringClass* (*__str__)(AnyClass self);

#define OBJECT_LITERAL \
    Object___init___impl, \
    Object___del___impl, \
    Object___repr___impl, \
    Object___str___impl,

#define STRING_MEMBERS \
    OBJECT_MEMBERS \
    char* (*toCharArray)(AnyClass self);

#define STRING_LITERAL \
    OBJECT_LITERAL \
    String_toCharArray_impl,


/**
 * Typedef struct definitions
 */
struct _ObjectClass {
    ClassProperties properties;
    OBJECT_MEMBERS
};
struct _StringClass {
    ClassProperties properties;
    STRING_MEMBERS
};

ObjectClass Object = {
    {
        sizeof(ObjectClass),
        NULL,
    },
    OBJECT_LITERAL
};
StringClass String = {
    {
        sizeof(StringClass),
        &Object,
    },
    STRING_LITERAL
};

/**
 * Free functions
 */
AnyClass new(AnyClass, ...);
void destroy(AnyClass);
StringClass* str(AnyClass);
void printStr(StringClass*);
AnyClass super(AnyClass self);

#endif
