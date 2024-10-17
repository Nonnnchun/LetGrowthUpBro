#include <stdio.h>

int main() {
    int n,a,max,min;
    printf("Enter number ");
    scanf("%d",&n);
    scanf("%d",&a);
    max = min = a;
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        if(a>max) {
            max = a;
        } if(a<min) {
            min = a;
        }
    }
    printf("%d\n%d",min,max);
    return 0;
}