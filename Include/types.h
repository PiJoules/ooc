#ifndef TYPES_H
#define TYPES_H

/**
 * Usable object types
 */
typedef void* Any;
typedef void* Method;
typedef void* Class;

typedef struct Object Object;
typedef struct String String;
typedef struct List List;

#define CLASS_PROPERTIES \
    Class cls;

typedef struct {
    CLASS_PROPERTIES
} ClassProperties;


#endif
