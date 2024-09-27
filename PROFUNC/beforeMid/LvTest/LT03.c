#include<stdio.h>
#include<string.h>

int LT3(){
    int num;
    printf("Input number : ");
    scanf("%d", &num);
    for(int i=1; i<=num; i++){
        for(int j=0; j<=num-1-i; j++){
            printf(" ");
        }
        for (int j = 1; j <= i; j++) {
            printf("%d", j);
        }
        for (int j = i-1; j >= 1; j--) {
            printf("%d", j);
        }
        printf("\n");
    }
}

int LT5(){
    char b[10];
    int size;
    printf("Input binary code: ");
    scanf("%s", b);
    printf("Input size: ");
    scanf("%d", &size);
    int length = strlen(b);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < length; j++) {
            if (b[j] == '1') {
                for (int k = 0; k < size; k++) {
                    printf("x");
                }
            } else {
                for (int k = 0; k < size; k++) {
                    printf(" ");
                }
            }
            printf("X");
        }
        printf("\n");
    }
}

int main(){
//    LT5();
    LT3();
    return 0;
}