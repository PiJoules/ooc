#include "All.h"

int main(int argc, char* argv[]){
#ifdef DEBUG
    printf("DEBUG flag set.\n");
#endif

    Object* obj = NEW(Object);
    destroy(obj);

    /**
     * Strings
     */
    Any str = NEW(EmptyString);
    destroy(str);

    Any str2 = NEW(String, "something");
    Any str3 = NEW(String, " else ");

    // String add
    Any str4 = ADD(str2, str3);
    
    // print
    println(str4);

    destroy(str2);
    destroy(str4);
    destroy(str3);

    return 0;
}

