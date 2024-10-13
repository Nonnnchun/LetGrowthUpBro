#include <stdio.h>
#include <string.h>

int main(){
    char string[1024];
    //digital signal
    /*  input signal = 011001
        size signal = 3
x xxxxx   xxx
x x   x   x x
xxx   xxxxx x
*/
    char inputSignal[1024];
    int sizeSignal;

    // รับ input
    printf("Enter binary code: ");
    scanf("%s", inputSignal);
    printf("Enter size signal: ");
    scanf("%d", &sizeSignal);

    int length = strlen(inputSignal);

    // แถวบนสุด
    for (int i = 0; i < length; i++) {
        if (inputSignal[i] == '1') {
            for (int j = 0; j < (2 * sizeSignal - 1); j++) {
                printf("x");
            }
        } else {
            printf("x");
            for (int j = 0; j < (2 * sizeSignal - 3); j++) {
                printf(" ");
            }
            printf("x");
        }
    }
    printf("\n");

    // แถวกลาง
    for (int i = 0; i < length; i++) {
        printf("x");
        for (int j = 0; j < (2 * sizeSignal - 3); j++) {
            printf(" ");
        }
        printf("x");
    }
    printf("\n");

    // แถวล่างสุด
    for (int i = 0; i < length; i++) {
        if (inputSignal[i] == '1') {
            printf("x");
            for (int j = 0; j < (2 * sizeSignal - 3); j++) {
                printf(" ");
            }
            printf("x");
        } else {
            for (int j = 0; j < (2 * sizeSignal - 1); j++) {
                printf("x");
            }
        }
    }
    printf("\n");

    return 0;
}
