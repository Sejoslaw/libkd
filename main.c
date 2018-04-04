#define LIBKD_IMPLEMENTED
#include "libkd.h"

int main(int argc, char *argv[])
{
    char *s1 = "String1-";
    printf("String1 = %s", s1);
    printf("\n\n");

    char *s2 = "-String2";
    printf("String2 = %s", s2);
    printf("\n\n");

    char *ret = LIBKD_StringAppend(s1, s2);
    printf("String3 = %s", ret);
    printf("\n\n");

    return 0;
}
