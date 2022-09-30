#include <stdbool.h>
#include <stdio.h>

#include "String.h"

int main(int argc, char const *argv[]) {
    Str *s1 = initStr();
    Str *s2 = initStr();
    assignStr(s1, "Hello World");
    printStr(s1);
    assignStr(s2, "hello world");
    printStr(s2);
    printf("Compare\t\t%d\n", compareStr(*s1, *s2));
    Str *s3 = initStr();
    concatStr(*s1, *s2, s3);
    printStr(s3);
    printf("free s3\n");
    freeStr(s3);
    printStr(s3);
    s3 = subStr(*s1, 5, 5);
    printStr(s3);
    int idx = KMP(*s1, *s3);
    printf("Find \"%s\" in \"%s\" at %d\n", s3->chs, s1->chs, idx);
    return 0;
}
