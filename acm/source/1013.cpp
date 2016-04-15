#include <stdio.h>
#include <string.h>

int main() {
    int value, len;
    char num[1010];

    while (scanf("%s", num) != EOF && num[0] != '0') {
        len = strlen(num);
        value = 0;
        for (int i = 0; i < len; i++) {
            value += num[i] - '0';
        }

        if (value <= 9) {
            printf("%d\n", value);
        } else {
            value %= 9;

            if (value == 0) {
                value = 9;
            }

            printf("%d\n", value);
        }
        
    }

    return 0;
}