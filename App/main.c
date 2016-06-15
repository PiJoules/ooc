#include <stdio.h>

#include "new.h"
#include "Object.h"
#include "Set.h"

int main(int argc, char* argv[]){
#ifdef DEBUG
    printf("DEBUG flag set.\n");
#endif

    void* s = new(Set);
    void* a = add(s, new(Object));
    void* b = add(s, new(Object));
    void* c = new(Object);

    if (contains(s, a) && contains(s, b)){
        printf("set contains a and b\n");
    }

    if (contains(s, c)){
        printf("set contains c\n");
    }

    if (differ(a, add(s, a))){
        printf("a and a added to set differ\n");
    }

    if (contains(s, drop(s, a))){
        printf("set contains the first dropped a\n");
    }

    delete(drop(s, b));
    delete(drop(s, c));

    return 0;
}

