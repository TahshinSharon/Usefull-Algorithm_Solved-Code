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
const int mxn=25;
int dx[]={+1,-1,+0,-0};
int dy[]={+0,-0,+1,-1};
int vis[mxn][mxn];
string s[mxn];
int w,h,cnt;
int valid(int x,int y){
    if(x>=0&&x<h&&y>=0&&y<w&&!vis[x][y]&&s[x][y]!='#'){
        return 1;
    }
    return 0;
}
void dfs(int i,int j){
    vis[i][j]=1;
    cnt++;
    for(int k=0;k<4;k++){
        int x=i+dx[k];
        int y=j+dy[k];
        if(valid(x,y)){
            dfs(x,y);
        }
    }
}
void solve() {
    cin>>w>>h;
    for(int i=0;i<h;i++){
        cin>>s[i];
    }
    cnt=0;
    memset(vis,0,sizeof(vis));
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(s[i][j]=='@'){
                dfs(i,j);
                break;
            }
        }
    }
    cout<<cnt<<nline;
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
