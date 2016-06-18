#ifndef ALL_H
#define ALL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>
#include <string.h>

#include "types.h"
#include "Object.h"
#include "String.h"
#include "functions.h"


/**
 * Macros
 */
// Call parent method
#define SUPER(parent_class, method, ...) ((parent_class*)(super(self)))->method(self, ##__VA_ARGS__)

// Typecasting shortcut
#define CAST(cls, obj) ((cls*) obj)
#define SELF(cls) CAST(cls, self)

// Get type
#define TYPE(obj) CAST(ClassProperties, obj)->type
#define SELF_TYPE TYPE(self)


#endif
