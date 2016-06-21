#ifndef FUNCTIONS_H
#define FUNCTIONS_H

/**
 * Free functions
 */
void destroy(Any obj);
char* formattedString(const char* fmt, ...);
void print_with_end(Any obj, char* end);
void print(Any obj);
void println(Any obj);
char* copyStr(const char* str);  // Just in case strdup() is not provided
void copyStrInplace(char* dest, const char* src, const size_t str_size);

#endif
