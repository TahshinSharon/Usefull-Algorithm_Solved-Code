#include<bits/stdc++.h>
using namespace std;
#define ll                  long long
#define ull                 unsigned long long LL
#define md                  10000007
#define pb                  push_back
#define mp                  make_pair
#define pp                  pair<LL,LL>
#define nline "\n"
void solve() {
	int n;
	cin >> n;
	int a[n + 2][n + 2] = {0};
	int pre[n + 2][n + 2] = {0};
	int mx = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			pre[i][j] = a[i][j] + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
		}
	}
	for (int x1 = 1; x1 <= n; x1++) {
		for (int y1 = 1; y1 <= n; y1++) {
			for (int x2 = x1; x2 <= n; x2++) {
				for (int y2 = y1; y2 <= n; y2++) {
					int tmp = pre[x2][y2] - pre[x1 - 1][y2] - pre[x2][y1 - 1] + pre[x1 - 1][y1 - 1];
					mx = max(tmp, mx);
				}
			}
		}
	}
	cout << mx << nline;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 1; i <= t; i++) {
		//cout<<"Case "<<i<<": ";
		solve();
	}
	return 0;
}