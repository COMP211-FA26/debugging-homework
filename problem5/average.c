#include <stdio.h>

int main(void) {
    int num_readings;
    int total = 0;

    scanf("%d", &num_readings);

    for (int i = 0; i < num_readings; i++) {
        int temperature;
        scanf("%d", &temperature);

        total += temperature;
    }

    int average = total / (num_readings + 1);

    printf("Average temperature: %d\n", average);

    return 0;
}