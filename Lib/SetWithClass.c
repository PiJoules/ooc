#include <stddef.h>
#include <assert.h>
#include <stdlib.h>
#include <stdarg.h>

struct Class {
    size_t size;
    void* (*ctor) (void* self, va_list* app);
    void* (*dtor) (void* self);
    void* (*clone) (const void* self);
    int (*differ) (const void* self, const void* other);
};

struct String {
    const void* class;  // This must be first
    char* text;
};

struct Set {
    const void* class;
    unsigned int count;  // number of elements in set
};

struct Object {
    unsigned int count;  // number of times element was added to set (reference counting)
    struct Set* in;  // Set this obj is in
};

static const size_t _Set = sizeof(struct Set);
static const size_t _Object = sizeof(struct Object);

const void* Set = &_Set;
const void* Object = &_Object;

void* new(const void* _class, ...){
    const struct Class* class = (const struct Class*)_class;
    void* p = (void*)calloc(1, class->size);

#ifdef DEBUG
    assert(p);
#endif

    *((const struct Class**) p) = class;

    if (class->ctor){
        va_list ap;
        va_start(ap, _class);
        p = class->ctor(p, &ap);
        va_end(ap);
    }

    return p;
}

void delete(void* self){
    const struct Class** cp = (const struct Class**)self;
    if (self && *cp && (*cp)->dtor){
        self = (*cp)->dtor(self);
    }
    free(self);
}

void* add(void* _set, const void* _element){
    struct Set* set = (struct Set*)_set;
    struct Object* element = (struct Object*)_element;

#ifdef DEBUG
    assert(set);
    assert(element);
#endif

    if (!(element->in)){
        element->in = set;
    }
    else {
#ifdef DEBUG
        assert(element->in == set);
#endif
    }

    (element->count)++;
    (set->count)++;
    return (void*)element;
}

void* find(const void* _set, const void* _element){
    const struct Object* element = (const struct Object*)_element;

#ifdef DEBUG
    assert(_set);
    assert(element);
#endif

    return element->in == _set ? (void*) element : 0;
}


int contains(const void* set, const void* element){
    return find(set, element) != 0;
}

void* drop(void* _set, const void* _element){
    struct Set* set = (struct Set*)_set;
    struct Object* element = find(set, _element);

    if (element){
        if (--(element->count) == 0){
            element->in = 0;
        }
        (set->count)--;
    }

    return (void*)element;
}

unsigned int count(const void* _set){
    const struct Set* set = (const struct Set*)_set;

#ifdef DEBUG
    assert(set);
#endif

    return set->count;
}

int differ(const void* a, const void* b){
    return a != b;
}
