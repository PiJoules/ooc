#include "All.h"

int main(int argc, char* argv[]){
#ifdef DEBUG
    printf("DEBUG flag set.\n");
#endif

    Any a = new_Object();
    println(a);
    destroy(a);

    Any s = new_String("something");
    println(s);
    destroy(s);

    return 0;
}

