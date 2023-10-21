#include<bits/stdc++.h>
using namespace std;
#define int                  long long
#define ull                 unsigned long long LL
#define MAX 500000
#define MOD 1000000007
#define INF INT_MAX
#define LINF LLONG_MAX
#define pi acos(-1.0)
#define F first
#define S second
#define pb                  push_back
#define mp                  make_pair
#define pp                  pair<LL,LL>
#define nline "\n"
int ab[MAX];
int bc[MAX];
int n,q,len;
vector<int>blk;
vector<int>a;
void build(int i,int val){
    blk[i/len]+=val;
    return;
}
int query(int l,int r){
    int c_l=l/len;
    int c_r=r/len;
    int sum=0;
    if(c_l==c_r){
        for(int i=l;i<=r;i++){
            sum+=a[i];
        }
    }
    else{
        for(int i=l,en=(c_l+1)*len-1;i<=en;i++){
            sum+=a[i];
        }
        for(int i=c_l+1;i<c_r;i++){
            sum+=blk[i];
        }
        for(int i=c_r*len;i<=r;i++){
            sum+=a[i];
        }
    }
    return sum;
}
void solve() {
    cin>>n>>q;
    blk.resize(n);
    a.resize(n);
    len=(int)sqrt(n+.0)+1;
    for(int i=0;i<n;i++){
        cin>>a[i];
        build(i,a[i]);
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        l--;
        r--;
        cout<<query(l,r)<<nline;
    }
}
int32_t main() {
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
