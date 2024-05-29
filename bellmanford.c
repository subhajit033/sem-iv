#include<stdio.h>

int main(){
	int dist[7];
	int v,i,j,k;
	int cost[7][7]={
		            {0,6,5,5,99,99,99},
		            {99,0,99,99,-1,99,99},
		            {99,-2,99,99,1,99,99},
		            {99,99,-2,99,99,-1,99},
		            {99,99,99,99,99,99,3},
		            {99,99,99,99,99,99,3},
		            {99,99,99,99,99,99,99},
	               };
	printf("Enter the sorce vertex :");
	scanf("%d",&v);
	for(i=0;i<7;i++){
		dist[i]=cost[v][i];
	}
	for(k=0;k<7-1;k++){
		for(i=0;i<7;i++){
			for(j=0;j<7;j++){
				if(cost[i][j]!=0 && cost[i][j]!=99){
					if(dist[j]>dist[i]+cost[i][j]){
						dist[j]=dist[i]+cost[i][j];
					}
				}
			}
		}
	}
	printf("Final distance matrix is :\n");
	for(i=0;i<7;i++){
		printf("%d\t",dist[i]);
	}
    printf("\n");
    return 0;
}
