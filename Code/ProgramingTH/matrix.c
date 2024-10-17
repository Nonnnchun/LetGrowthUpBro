#include <stdio.h>

int main(){
    int m,n; //m=rows,n=columns
    scanf("%d",&m);
    scanf("%d",&n);

    int matrix1[m][n], matrix2[m][n], total[m][n];
    //matrix1 input
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            scanf("%d",&matrix1[i][j]);
        }
    }
    //matrix2 input
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            scanf("%d",&matrix2[i][j]);
        }
    }
    //sum of matrix
    printf("----------------------------------------------------------------\n");
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            total[i][j]=matrix1[i][j]+matrix2[i][j];
            printf("%d ",total[i][j]);
        }
        printf("\n");
    }
    return 0;
}