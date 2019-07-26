#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,i,j,s;
    printf("Enter no. of vertices: ");
    scanf("%d",&n);
    int **cost=(int**)malloc((n+1)*sizeof(int*));
    for(i=1;i<=n;i++)
        cost[i]=(int*)malloc((n+1)*sizeof(int));
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("Enter cost[%d][%d] ",i,j);
            scanf("%d",&cost[i][j]);
        }
    }
    printf("\ncost Matrix: \n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(cost[i][j]==999)
                printf("%c ",236);
            else
                printf("%d ",cost[i][j]);
        }
        printf("\n");
    }
    printf("Enter source vertex: ");
    scanf("%d",&s);
    int check=bellman_ford(cost,n,s);
    if(check==0)
        printf("\nThe graph is having negative weight cycle\n");
    return 0;
}
int bellman_ford(int **cost,int n,int s)
{
    int i,j,k;
    int *dis=(int*)malloc((n+1)*sizeof(int));
    for(i=1;i<=n;i++)
        dis[i]=999;
    dis[s]=0;
    for(i=1;i<=n-1;i++)
    {
        for(j=1;j<=n;j++)
        {
            for(k=1;k<=n;k++)
            {
                if(cost[j][k]!=0 && cost[j][k]!=999)
                {
                    if(dis[j]+cost[j][k]<dis[k])
                        dis[k]=dis[j]+cost[j][k];
                }
            }
        }
    }
    for(j=1;j<=n;j++)
    {
        for(k=1;k<=n;k++)
        {
            if(cost[j][k]!=0 && cost[j][k]!=1)
            {
                if(dis[j]+cost[j][k]<dis[k])
                    return 0;
            }
        }
    }
    for(i=1;i<=n;i++)
        printf("\nDistance from %d to %d is %d\n",s,i,dis[i]);
    return 1;
}
