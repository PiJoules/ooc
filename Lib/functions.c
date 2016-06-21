#include "All.h"

#define FMT_BUFFER_SIZE 256

/**
 * Destroy an object
 */
void destroy(Any obj){
    CALL(void, (Any), CAST(Object, obj), del);
    free(obj);
}

/**
 * Copy a string
 */
char* copyStr(const char* str_){
    const size_t str_size = sizeof(char) * strlen(str_);
    char* str = (char*)malloc(str_size + 1);
    copyStrInplace(str, str_, str_size);
    return str;
}

/**
 * Copy a string inplace.
 */
void copyStrInplace(char* dst, const char* src, const size_t str_size){
    strncpy(dst, src, str_size);
    dst[str_size] = '\0';
}

/**
 * Create a new formatted string.
 */
char* formattedString(const char* fmt, ...){
    va_list args;
    va_start(args, fmt);

    char buffer[FMT_BUFFER_SIZE];
    int n = sprintf(buffer, fmt, args);

#ifdef DEBUG
    assert(n >= 0);
#endif

    va_end(args);

    return copyStr(buffer);
}

/**
 * Print an object.
 */
void print_with_end(Any obj, char* end){
    String* str_obj = STR(obj);
    printf("%s%s", str_obj->value, end);
    destroy(str_obj);
}

void print(Any obj){
    print_with_end(obj, "");
}
void println(Any obj){
    print_with_end(obj, "\n");
}
