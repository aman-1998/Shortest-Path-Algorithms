#include<stdio.h>
#include<stdlib.h>

int heap_size;
struct node
{
    int v,d;
};
struct node min;
void dijkstra(int **cost,int n,int s);
struct node *build_heap(struct node A[]);
struct node *min_heapify(struct node A[],int i);
struct node *delete_min(struct node A[]);
struct node *decrease_key(struct node A[],int i,int key);

int main()
{
    int n,s,i,j;
    printf("Enter no. of vertices: ");
    scanf("%d",&n);
    int **cost=(int**)malloc((n+1)*sizeof(int*));
    for(i=0;i<=n;i++)
        cost[i]=(int*)malloc((n+1)*sizeof(int));
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("Enter cost[%d][%d]: ",i,j);
            scanf("%d",&cost[i][j]);
        }
    }
    printf("Directed weight matrix: \n");
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
    printf("Enter the source vertex: ");
    scanf("%d",&s);
    dijkstra(cost,n,s);
    return 0;
}
void dijkstra(int **cost,int n,int s)
{
    int i,j,k;
    struct node *A=(struct node*)malloc((n+1)*sizeof(struct node));
    for(i=1;i<=n;i++)
    {
        A[i].v=i;
        A[i].d=999;
    }
    A[s].d=0;
    heap_size=n;
    A=build_heap(A);
    for(i=1;i<=n;i++)
    {
        A=delete_min(A);
        printf("\nShortest distance from %d to %d is %d",s,min.v,min.d);
        for(j=1;j<=n;j++)
        {
            if(cost[min.v][j]!=0 && cost[min.v][j]!=999);
            {
                for(k=1;k<=heap_size;k++)
                {
                    if(A[k].v==j)
                    {
                        if(min.d+cost[min.v][j]<A[k].d)
                            A=decrease_key(A,k,min.d+cost[min.v][j]);
                    }
                }
            }
        }
    }
}
struct node *build_heap(struct node A[])
{
    int i;
    for(i=heap_size/2;i>=1;i--)
        A=min_heapify(A,i);
    return A;
}
struct node *min_heapify(struct node A[],int i)
{
    int l,r,smallest;
    struct node temp;
    l=2*i;
    r=2*i+1;
    if(l<=heap_size && A[l].d<A[i].d)
        smallest=l;
    else
        smallest=i;
    if(r<=heap_size && A[r].d<A[smallest].d)
        smallest=r;
    if(smallest!=i)
    {
        temp=A[i];
        A[i]=A[smallest];
        A[smallest]=temp;
        A=min_heapify(A,smallest);
    }
    return A;
}
struct node *delete_min(struct node A[])
{
    min=A[1];
    A[1]=A[heap_size];
    heap_size--;
    A=min_heapify(A,1);
    return A;
}
struct node *decrease_key(struct node A[],int i,int key)
{
    struct node temp;
    if(i<1 || i>heap_size || key>=A[i].d)
    {
        printf("\nError");
        exit(1);
    }
    A[i].d=key;
    while(i>1 && A[i].d<A[i/2].d)
    {
        temp=A[i];
        A[i]=A[i/2];
        A[i/2]=temp;
        i=i/2;
    }
    return A;
}
