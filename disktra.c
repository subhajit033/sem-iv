#include<stdio.h>
#include<limits.h>

#define n 6 // global hi le lete h 

int main(int argc, char const *argv[])
{
    /* code */
    int cost[][6] = {{0,2,4,99,99,99},
                    {99,0,1,7,99,99},
                    {99,99,0,99,3,99},
                    {99,99,99,0,99,1},
                    {99,99,99,2,0,5},
                    {99,99,99,99,99,0}
                    };

    int src;
    printf("source vertex kya hai : ");
    scanf("%d", &src);
    int dist[n];
    int vis[n];
    for(int i = 0 ; i <n ; i ++){
        vis[i] = 0;
    }

    for(int i = 0 ; i<n ; i++){
        dist[i] = cost[src-1][i];
    }   
    vis[src-1] = 1;

    int u,v;
    for(int i = 0 ; i<n-1; i++){
        int min = INT_MAX;
        for(int j =0 ; j<n;j++){
            if(vis[j]!= 1 && dist[j]<min) {
                min = dist[j];
                u = j;
            }
        }

        vis[u] = 1;
        for(v = 0 ; v<n; v++){
            if(v!= u){  // this condition is also not necessary;
                if((dist[u]+cost[u][v])<dist[v]){
                    dist[v] = dist[u]+ cost[u][v];
                }
            }
        }
        
    }
    printf("\nFinal Distance Matrix : \n");
	for(int i=0;i<n;i++)
	{
		printf("\t%d",dist[i]);
		
		
	}

    return 0;
}
