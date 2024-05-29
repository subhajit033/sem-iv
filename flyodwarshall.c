#include<stdio.h>

int min(int a, int b){
    if(a > b){
        return b;
    }else{
        return a;
    }
}

int main(){
    int j, k, i;
    int A[4][4]={
        {0,3,99,7},
        {8,0,2,99},
        {5,99,0,1},
        {2,99,99,0},
    };

    for(k=0; k<4; k++){
        for(i=0; i<4; i++){
            for(j=0; j<4; j++){
                A[i][j] = min(A[i][j], (A[i][k]+A[k][j]));
            }
        }
    }
    for(i=0; i<4; i++){
        for(j=0; j<4; j++){
            printf("%d\t", A[i][j]);
        }
        printf("\n");
    }
    return 0;
}
