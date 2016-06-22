#include "All.h"

int main(int argc, char* argv[]){
#ifdef DEBUG
    printf("DEBUG flag set.\n");
#endif

    /**
     * Object
     */
    Any obj = NEW(Object);
    Any obj2 = COPY(obj);

    // Equals
    assert(EQUALS(obj, obj));
    assert(EQUALS(obj, obj2));

    destroy(obj2);

    /**
     * Strings
     */
    Any str = NEW(EmptyString);
    destroy(str);

    Any str2 = NEW(String, "something");
    Any str3 = NEW(String, " else");
    Any str2cpy = COPY(str2);
    Any str2cpycpy = COPY(str2cpy);

    // Equals
    assert(!EQUALS(obj, str2));
    assert(!EQUALS(str2, obj));
    assert(EQUALS(str2, str2));
    assert(EQUALS(str2cpy, str2cpycpy));
    assert(!EQUALS(str2, str3));

    // String add
    Any str4 = ADD(str2, str3);
    Any str5 = NEW(String, "something else");
    assert(EQUALS(str4, str5));
    destroy(str5);
    
    // print
    println(str4);


    /**
     * List
     */
    Any lst = NEW(LinkedList);
    destroy(lst);

    destroy(str2);
    destroy(str4);
    destroy(str3);
    destroy(obj);
    destroy(str2cpy);
    destroy(str2cpycpy);

    return 0;
}

