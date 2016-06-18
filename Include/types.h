#ifndef TYPES_H
#define TYPES_H

/**
 * Usable object types
 */
typedef void* Any;
typedef struct Object Object;
typedef struct String String;

/**
 * Common class properties that all classes must include as the first member.
 */
typedef struct {
    const size_t size;
    const Any type;
    const Any parent;
} ClassProperties;

#endif
