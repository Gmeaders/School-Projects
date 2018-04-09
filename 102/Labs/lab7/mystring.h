#ifndef MYSTRING_H
#define MYSTRING_H

// string length
size_t my_strlen(const char *str);

// string copy functions
char *my_strcpy(char *destination, const char *source);
char *my_strncpy(char *destination, const char *source, size_t num);
size_t my_strlcpy(char *destination, const char *source, size_t dstsize);

#endif