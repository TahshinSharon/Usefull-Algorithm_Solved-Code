#include<iostream>
using namespace std;
#define max 10005
int ar[max][max],pre[max][max],res;
int n,m,q;
int main()
{
    printf("Enter The Row And Coloumn Of the 2D Array\n");
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&ar[i][j]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            pre[i][j]=ar[i][j]+pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("%d ",pre[i][j]);
        }
        printf("\n");
    }
    printf("Enter The Number Of Query\n");
    scanf("%d",&q);
    while(q--){
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        res=pre[x2][y2]-pre[x1-1][y2]-pre[x2][y1-1]+pre[x1-1][y1-1];
        printf("%d\n",res);
    }
    return 0;
}