#include <stdio.h>

int main(void) {
    int weights[] = {4, 12, 7, 28, 18, 6, 31, 14};
    int shipping = 0;

    for (int i = 0; i < 8; i++) {
        if (weights[i] > 10) {
            shipping = 8;
        } else if (weights[i] > 25) {
            shipping = 12;
        } else {
            shipping = 5;
        }

        printf("Package %d: %d lbs, shipping $%d\n", i, weights[i], shipping);
    }

    return 0;
}