#include <stdio.h>

int main(void) {
    int temperatures[] = {68, 72, 70, 75, 71, 74, 69};
    int max = temperatures[0];

    for (int i = 1; i < 7; i++) {
        if (temperatures[i] > max) {
            max = i;
        }
    }

    printf("Maximum temperature: %d\n", max);

    return 0;
}