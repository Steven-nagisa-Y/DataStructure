#include <stdio.h>

#include "Stack.h"

bool matchBrackets(char c[], int n) {
    char stack[MAX_SIZE];
    int top = -1;
    for (int i = 0; i < n; ++i) {
        if (c[i] == '(' || c[i] == '[' || c[i] == '{') stack[++top] = c[i];
        if (c[i] == ')' || c[i] == ']' || c[i] == '}') {
            if (top == -1)
                return false;
            else {
                --top;
            }
        }
    }
    if (top == -1)
        return true;
    else
        return false;
}

int main(int argc, char const *argv[]) {
    char brackets[] = "()([[])[{()}]{[]}";
    bool isMatch = matchBrackets(brackets, 18);
    printf("%s is match? %d", brackets, isMatch);
    return 0;
}
