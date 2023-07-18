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
const int N=3e4+7;
vector<pair<int,int> >g[N];
int d[N];
void dfs(int u,int p){
    for(auto v:g[u]){
        if(v.F!=p){
            d[v.F]=d[u] + v.S;
            dfs(v.F,u);
        }
    }
}
void solve() {
    int n;
    cin>>n;
    int u,v,w;
    for(int i=0;i<n-1;i++){
        cin>>u>>v>>w;
        u++,v++;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    d[1]=0;
    dfs(1,0);
    int mx=0,far=1;
    for(int i=1;i<=n;i++){
        if(d[i]>mx){
            mx=d[i];
            far=i;
        }
    }
    int s=far;
    d[s]=0;
    dfs(s,0);
    mx=0;
    for(int i=1;i<=n;i++){
        if(d[i]>mx){
            mx=d[i];
            far=i;
        }
    }
    cout<<d[far]<<nline;
    for(int i=0;i<=n;i++){
        g[i].clear();
        d[i]=0;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout<<"Case "<<i<<": ";
        solve();
    }
    return 0;
}
