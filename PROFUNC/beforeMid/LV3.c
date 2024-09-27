#include<stdio.h>

void LV3() {
    int n; 
    printf("Input: ");
    scanf("%d", &n);

    int a = 0, b = 1, c;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            printf("%d ", a);
            continue;
        }
        if (i == 1) {
            printf("%d ", b);
            continue;
        }
        c = a + b;
        a = b;
        b = c;
        printf("%d ", c);
    }
}

void LV2(){
    char c;
    int n;
    printf("Enter your char: ");
    scanf("%c",&c);
    printf("Enter number of you char: ");
    scanf("%d",&n);
    for(int i=0; i<n; ++i){
        printf("%c ",c);
    }
}


int main(){
//    LV2();
    LV3();
}