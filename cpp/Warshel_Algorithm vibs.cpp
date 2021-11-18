#include<stdio.h>
int n,a[10][10],p[10][10];
void path()
{
    int i,j,k;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            p[i][j]=a[i][j];
        }
    }
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
            if(p[i][k]==1 && p[k][j]==1)
            p[i][j]=1;
            }
        }
    }
}
int main()
{

    int i,j,r,x,y;
    for(i=0;i<10;i++)
    {for(j=0;j<10;j++)
      {  a[i][j]=0;}

    }
    printf("enter no. of nodes");

      scanf("%d",&n);
      printf("enter no. of elements in set");
      scanf("%d",&r);
      for(i=0;i<r;i++)
      {scanf("%d %d",&x,&y);
      a[x][y]=1;

      }

    printf("Corresponding adjacency matrix");
    printf("\n");
    int h=1;
    int u=1;
    printf("  %d",u++);
    while(u<=n)
    {
        printf(" %d",u++);
    }
    printf("\n");
     for(i=0;i<n;i++)
    {printf("%d ",h++);
        for(j=0;j<n;j++)
        printf("%d ",a[i][j]);
        printf("\n");
    }

    path();
    printf("\n");
    printf("adjacency matrix fulfilling transitive closure\n");
    int o=1;
    int e=1;
    printf("  %d",e++);
    while(e<=n)
    {
        printf(" %d",e++);
    }
    printf("\n");
    for(i=0;i<n;i++)
    {printf("%d ",o++);
        for(j=0;j<n;j++)
        printf("%d ",p[i][j]);
        printf("\n");
    }
    printf("\n");
    printf("Relation fulfilling transitive closure :\t");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
         if(p[i][j]==1)
         {
             printf("(%d,%d)",i ,j);
         }
        }
    }
    return 0;
}
