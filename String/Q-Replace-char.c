#include <stdio.h>

#include "String.h"

void replace(Str *str, char ex, char new) {
    for (int i = 0; i < str->len; ++i) {
        if (str->chs[i] == ex) str->chs[i] = new;
    }
}

int main(int argc, char const *argv[]) {
    Str *str = initStr();
    assignStr(str, "Enemy is reaching, push harder.");
    printStr(str);
    replace(str, 'e', '$');
    printStr(str);
    return 0;
}
