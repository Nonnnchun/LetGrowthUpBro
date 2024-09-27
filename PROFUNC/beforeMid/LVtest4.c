#include <stdio.h>

void LV4() {
    int p, n;
    printf("Input size: ");
    scanf("%d", &n);
    printf("Input round: ");
    scanf("%d", &p);

    printf("*\n");
    if(n == 1){
        while(n < 3){
            printf("*\n");
            n++;
        } 
        } else {
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < j; k++) {
                printf(" ");
            } if(j==0){
                printf("");
            } else {printf("*\n");}
        }
        for (int j = n - 2; j >= 0; j--) {
            for (int k = 0; k < j; k++) {
                printf(" ");
            }
            printf("*\n");
            } 
        }
    }
}


//zigzag
int main(){
    LV4();
}

//เปลี่ยนเป็นเลข