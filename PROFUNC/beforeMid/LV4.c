#include <stdio.h>

int main() {
    int numbers[7];
    int i, max1, max2;
    for (i = 0; i < 7; i++) {
        printf("Input: ");
        scanf("%d", &numbers[i]);
    }

    for (i = 0; i < 7; i++) {
        if (numbers[i] > max1) {
            max2 = max1;
            max1 = numbers[i];
        } else if (numbers[i] > max2 && numbers[i] < max1) {
            max2 = numbers[i];
        }
    }

    printf("Output: %d\n", max2);

    return 0;
}
