#include "String.h"

void reverse(Str *str) {
    int i = 0, j = str->len - 1;
    for (; i < j; ++i, --j) {
        char tmp = str->chs[i];
        str->chs[i] = str->chs[j];
        str->chs[j] = tmp;
    }
}

int main(int argc, char const *argv[]) {
    Str *str = initStr();
    assignStr(str, "The codes");
    printStr(str);
    reverse(str);
    printStr(str);
    return 0;
}
