#include "All.h"

int main(int argc, char* argv[]){
#ifdef DEBUG
    printf("DEBUG flag set.\n");
#endif

    /**
     * Object tests
     */
    Any a = new_Object();
    Any a2 = new_Object();

    // Addition
    Any a3 = CAST(Object, a)->add(a, a2);

    // Equality
    assert(CAST(Object, a)->equals(a, a2));
    assert(CAST(Object, a2)->equals(a2, a3));
    assert(CAST(Object, a3)->equals(a3, a));

    // Printing
    print(a);
    print(a3);

    // Destruction
    destroy(a3);
    destroy(a2);

    /**
     * String tests
     */
    Any s = new_String("printing works.");

    // Addition
    Any s1 = new_String("First");
    Any s2 = new_String("Second");
    Any s3 = CAST(String, s1)->add(s1, s2);

    // Copy
    Any s4 = CAST(String, s1)->copy(s1);

    // Equality
    assert(!CAST(String, s1)->equals(s1, a));
    assert(CAST(String, s1)->equals(s1, s4));
    assert(CAST(String, s4)->equals(s4, s1));

    // Printing
    println(s);
    println(s3);

    // Destruction
    destroy(s4);
    destroy(s3);
    destroy(s2);
    destroy(s1);
    destroy(s);
    destroy(a);

    return 0;
}

