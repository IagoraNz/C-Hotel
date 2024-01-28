#include "../cliente.h"

void replaceUnderscoreWithSpace(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] == '_') {
            str[i] = ' ';
        }
    }
}

