#include "All.h"

Any new(const Any _cls){
    Object* cls = (Object*)_cls;
    const size_t size = cls->properties.size;
    Any obj = (Any)malloc(size);

#ifdef DEBUG
    assert(obj);
#endif

    memcpy(obj, _cls, size);
    return obj;
}

void destroy(Any obj){
    CAST(Object, obj)->del(obj);
    free(obj);
}

Any super(Any self){
    return ((ClassProperties*) self)->parent;
}

void print(const Any _obj){
    Object* obj = (Object*) _obj;
    String* _str = obj->str(obj);
    printf("%s", _str->toCharArray(_str));
    destroy(_str);
}
void println(const Any _obj){
    Object* obj = (Object*) _obj;
    String* _str = obj->str(obj);
    printf("%s\n", _str->toCharArray(_str));
    destroy(_str);
}
