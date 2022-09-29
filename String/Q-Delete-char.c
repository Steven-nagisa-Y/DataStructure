#include <stdlib.h>

#include "String.h"

void deleteStr(Str *str, char t) {
    int count = 0;
    for (int i = 0; i < str->len; ++i)
        if (str->chs[i] == t) ++count;
    if (count == 0) return;
    char *chs = (char *)malloc(sizeof(char) * (str->len - count + 1));
    int j = 0;
    for (int i = 0; i < str->len; ++i)
        if (str->chs[i] != t) chs[j++] = str->chs[i];
    chs[j] = '\0';
    str->len = str->len - count;
    free(str->chs);
    str->chs = chs;
}

int main(int argc, char const *argv[]) {
    Str *str = initStr();
    assignStr(str, "world is in control");
    printStr(str);
    deleteStr(str, 'o');
    printStr(str);
    return 0;
}
