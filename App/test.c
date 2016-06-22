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

    // Append
    APPEND(lst, obj);
    APPEND(lst, obj);
    APPEND(lst, str4);
    APPEND(lst, lst);
    assert(LEN(lst) == 4);

    // Remove
    REMOVE(lst, obj);
    assert(LEN(lst) == 3);
    REMOVE(lst, obj);
    assert(LEN(lst) == 2);
    assert(EQUALS(CAST(LinkedList, lst)->first->value, str4));
    assert(EQUALS(CAST(LinkedList, lst)->last->value, lst));
    REMOVE(lst, str4);
    REMOVE(lst, lst);
    assert(LEN(lst) == 0);
    assert(!CAST(LinkedList, lst)->first);
    assert(!CAST(LinkedList, lst)->last);

    // Remove at
    APPEND(lst, obj);
    APPEND(lst, obj);
    APPEND(lst, str4);
    APPEND(lst, lst);

    REMOVE_AT(lst, 1);
    assert(LEN(lst) == 3);
    REMOVE_AT(lst, 0);
    assert(LEN(lst) == 2);
    assert(EQUALS(CAST(LinkedList, lst)->first->value, str4));
    assert(EQUALS(CAST(LinkedList, lst)->last->value, lst));
    REMOVE_AT(lst, 1);
    REMOVE_AT(lst, 0);
    assert(LEN(lst) == 0);
    assert(!CAST(LinkedList, lst)->first);
    assert(!CAST(LinkedList, lst)->last);

    // Slice
    APPEND(lst, obj);
    APPEND(lst, obj);
    APPEND(lst, str4);
    APPEND(lst, lst);

    Any lst2 = SLICE(lst, 2, 4);
    assert(LEN(lst2) == 2);
    assert(EQUALS(CAST(LinkedList, lst2)->first->value, str4));
    assert(EQUALS(CAST(LinkedList, lst2)->last->value, lst));
    Any lst3 = NEW(LinkedList);
    APPEND(lst3, str4);
    APPEND(lst3, lst);
    assert(EQUALS(lst3, lst2));
    assert(EQUALS(lst3, lst3));
    assert(EQUALS(lst2, lst3));
    assert(!EQUALS(lst3, lst));
    assert(!EQUALS(lst, lst2));
    destroy(lst2);
    destroy(lst3);

    // ITERATE
    APPEND(lst, obj);
    APPEND(lst, obj);
    APPEND(lst, str4);
    APPEND(lst, lst);

    ITERATE(lst, obj_iter){
        println(obj_iter);
    }

    // ENUMERATE

    destroy(str2);
    destroy(str4);
    destroy(lst);
    destroy(str3);
    destroy(obj);
    destroy(str2cpy);
    destroy(str2cpycpy);

    return 0;
}

