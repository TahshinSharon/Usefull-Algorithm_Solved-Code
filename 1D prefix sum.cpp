#include<iostream>
using namespace std;
#define max 100005
#define ll long long
ll ar[max],prefix[max];
int n,q,l,r;
void solve()
{
    int sum;
    scanf("%d %d",&n,&q); //input the array size and number of query
    for(int i=1;i<=n;i++)scanf("%d",&ar[i]); //insert the array value
    for(int j=1;j<=n;j++)prefix[j]=prefix[j-1]+ar[j]; //calculate the prefix array and store it into prefix array
    while(q--)
    {
        scanf("%d %d",&l,&r); //insert the index of query
        sum=prefix[r]-prefix[l-1]; //calculate the query sum from prefix array
        printf("%d\n",sum); //print it
    }
}
int main()
{
    solve();
    return 0;
}