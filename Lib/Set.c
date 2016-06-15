#if !defined MAX_HEAP_SIZE || MAX_HEAP_SIZE < 1
#define MAX_HEAP_SIZE 10
#endif

#include <assert.h>

const void* Set;
const void* Object;

/**
 * First element of heap will be used to indicate the maiximum
 * size of the heap, so elements are instead inserted starting
 * at heap[1].
 */
static int heap[MAX_HEAP_SIZE];
const static int DEFAULT_VALUE = MAX_HEAP_SIZE;  // Arbitrary default value (that shouldn't be zero) for elements in the set

/**
 * Return an element in the heap with a value 0.
 */
void* new(const void* type, ...){
    int *p;  // &heap[1]
    for (p = heap + 1; p < heap + MAX_HEAP_SIZE; p++){
        if (!(*p)){
            break;
        }
    }

#ifdef DEBUG
    assert(p < heap + MAX_HEAP_SIZE);
#endif

    *p = DEFAULT_VALUE;  // Set initial value of this element
    return (void*)p;
}


void delete(void* item_){
    int* item = (int*)item_;

    // Check for null pointer
    if (item){
#ifdef DEBUG
        assert(item > heap && item < heap + MAX_HEAP_SIZE);
#endif
        *item = 0;
    }
}

/**
 * The hash for elements in this set will be the distance of the set
 * from the start of the heap.
 */
void* add(void* _set, const void* _element){
    const int* set = (const int*)_set;
    const int* element = (const int*)_element;

#ifdef DEBUG
    assert(set > heap && set < heap + MAX_HEAP_SIZE);
    assert(*set == DEFAULT_VALUE);
    assert(element > heap && element < heap + MAX_HEAP_SIZE);
#endif

    // The value at this pointer refers only to this one set
    if (*element == DEFAULT_VALUE){
        *((int*)element) = set - heap;
    }
#ifdef DEBUG
    else {
        assert(*element == (set - heap));
    }
#endif

    return (void*) element;
}


void* find(const void* _set, const void* _element){
    const int* set = (const int*)_set;
    const int* element = (const int*)_element;

#ifdef DEBUG
    assert(set > heap && set < heap + MAX_HEAP_SIZE);
    assert(*set == DEFAULT_VALUE);
    assert(element > heap && element < heap + MAX_HEAP_SIZE);
    assert(*element);
#endif

    return *element == set - heap ? (void*) element : 0;
}

int contains(const void* set, const void* element){
    return find(set, element) != 0;
}

void* drop(void* _set, const void* _element){
    int* element = (int*)find(_set, _element);
    if (element){
        *element = DEFAULT_VALUE;
    }
    return (void*)element;
}

int differ(const void* a, const void* b){
    return a != b;
}
