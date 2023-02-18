#include<bits/stdc++.h>
using namespace std;
#define ll                  long long
#define ull                 unsigned long long LL
#define md                  107
#define pb                  push_back
#define mp                  make_pair
#define pp                  pair<LL,LL>
#define nline "\n"
ll v[md][md][md];
ll pre[md][md][md];
void solve() {
    int n, m, l;
    cin >> n >> m >> l;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= l; k++) {
                cin >> v[i][j][k];
                pre[i][j][k] = pre[i - 1][j][k] + pre[i][j - 1][k] + pre[i][j][k - 1] - pre[i - 1][j - 1][k] - pre[i - 1][j][k - 1] - pre[i][j - 1][k - 1] + pre[i - 1][j - 1][k - 1] + v[i][j][k];
            }
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int x1, x2, y1, y2, z1, z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        ll ans = pre[x2][y2][z2] - pre[x1 - 1][y2][z2] - pre[x2][y1 - 1][z2] - pre[x2][y2][z1 - 1] + pre[x1 - 1][y1 - 1][z2] + pre[x1 - 1][y2][z1 - 1] + pre[x2][y1 - 1][z1 - 1] - pre[x1 - 1][y1 - 1][z1 - 1];
        cout << ans << nline;
    }
    for (int i = 0; i <= n + 5; i++)
        for (int j = 0; j <= m + 5; j++)
            for (int k = 0; k <= l + 5; k++)pre[i][j][k] = 0;
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