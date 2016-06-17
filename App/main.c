#include "All.h"

/**
 * Object Defintions
 */
void Object___init___impl(AnyClass self, ...){
    va_list args;
    va_start(args, self);

    va_end(args);
}
void Object___del___impl(AnyClass self){}

StringClass* Object___repr___impl(AnyClass self){
    return (StringClass*) new((AnyClass)&String, "<object Object at ");
}

StringClass* Object___str___impl(AnyClass self){
    return (StringClass*) new((AnyClass)&String, "a");
}



/**
 * String defintions
 */
void String___init___impl(AnyClass self, ...){
    SUPER(ObjectClass, __init__, 12, 34);
}
void String___del___impl(AnyClass self){}
char* String_toCharArray_impl(AnyClass self){
    return "a";
}



// START OF FREE FUNCTIONS
AnyClass new(AnyClass _cls, ...){
    ObjectClass* cls = (ObjectClass*)_cls;
    const size_t size = cls->properties.size;
    AnyClass obj = (AnyClass)malloc(size);

#ifdef DEBUG
    assert(obj);
#endif

    memcpy(obj, _cls, size);

    va_list args;
    va_start(args, _cls);
    ((ObjectClass*) obj)->__init__((ObjectClass*) obj, args);
    va_end(args);

    return obj;
}

void destroy(AnyClass obj){
    ((ObjectClass*) obj)->__del__(obj);
    free(obj);
}

AnyClass super(AnyClass self){
    return ((ObjectClass*) self)->properties.parent;
}

/**
 * Override any methods for parent classes.
 *
 * This is a dirty hack since all classes should be defined at compile
 * time, but I have not found a legal way that allows me to create a class
 * that overrides the parent's method without having to explicitly state
 * all other parent attributes when overriding a method.
 */
void overrides(){
    String.__init__ = String___init___impl;
}

StringClass* str(AnyClass obj){
    return ((ObjectClass*) obj)->__str__((ObjectClass*) obj);
}
// END OF FREE FUNCTIONS


int main(int argc, char* argv[]){
    overrides();

#ifdef DEBUG
    printf("DEBUG flag set.\n");
#endif

    AnyClass a = new((AnyClass) &Object);
    //printf("%s\n", str(a));
    destroy(a);
    AnyClass s = new((AnyClass) &String);
    destroy(s);


    return 0;
}

