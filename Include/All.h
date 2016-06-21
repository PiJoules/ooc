#ifndef ALL_H
#define ALL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>
#include <string.h>
#include <stddef.h>

#include "types.h"
#include "Object.h"
#include "String.h"
#include "functions.h"


/**
 * macros
 */
// Casting to types
#define CAST(cls, obj) ((cls*) obj)
#define SELF(cls) CAST(cls, self)

// Calling functions
#define CALL(return_type, arg_types, obj, method, ...) ((return_type (*)arg_types) obj->method)(obj, ##__VA_ARGS__)
#define SELF_CALL(return_type, arg_types, cls, method, ...) CALL(return_type, arg_types, CAST(cls, self), method, ##__VA_ARGS__)
#define SUPER_CALL(return_type, arg_types, cls, method, ...) ((return_type (*)arg_types) cls ## Class.method)(self, ##__VA_ARGS__)

// Creating new instances
#define CREATE(cls) \
    const size_t obj_size = sizeof(cls); \
    cls* obj = (cls*)malloc(obj_size); \
    memcpy(obj, &cls ## Class, obj_size);

// Calling constructors
#define NEW(constructor, ...) new_ ## constructor(__VA_ARGS__)

// Assign overrided methods
#define APPLY_OVERRIDES(cls) cls ## _overrides(obj);


#endif
