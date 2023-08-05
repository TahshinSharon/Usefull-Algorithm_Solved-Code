#include<bits/stdc++.h>
using namespace std;
#define ll                  long long
#define ull                 unsigned long long LL
#define MAX 500000
#define MOD 100000007
#define INF INT_MAX
#define LINF LLONG_MAX
#define pi acos(-1.0)
#define F first
#define S second
#define pb                  push_back
#define mp                  make_pair
#define pp                  pair<LL,LL>
#define nline "\n"
const int N=1e5+7;
int ab[MAX];
int bc[MAX];
int h[N];
int dp[N];
int func(int n){
    if(n==0){
        return 0;
    }
    int cost=INT_MAX;
    if(dp[n]!=-1)
        return dp[n];
    cost=min(cost,func(n-1)+abs(h[n]-h[n-1]));
    if(n>1)
        cost=min(cost,func(n-2)+abs(h[n]-h[n-2]));
    return dp[n]=cost;
}
void solve() {
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    cout<<func(n-1)<<nline;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        //cout<<"Case "<<i<<": ";
        solve();
    }
    return 0;
}
