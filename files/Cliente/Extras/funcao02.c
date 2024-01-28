#include "../cliente.h"

void replaceSpaceWithUnderscore(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] == ' ') {
            str[i] = '_';
        }
    }
}
