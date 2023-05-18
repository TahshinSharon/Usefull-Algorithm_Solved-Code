#include<bits/stdc++.h>
using namespace std;
#define ll                  long long
#define ull                 unsigned long long LL
#define md                  10000007
#define pb                  push_back
#define mp                  make_pair
#define pp                  pair<LL,LL>
#define nline "\n"
ll w, h, n;
ll ok(ll x) {
	return ((x / w) * (x / h)) >= n;
}
void solve() {
	cin >> w >> h >> n;
	ll l = 0, r = 1;
	while (!ok(r)) {
		r *= 2;
	}
	while (l + 1 < r) {
		ll mid = l + (r - l) / 2;
		if (ok(mid)) {
			r = mid;
		}
		else {
			l = mid;
		}
	}
	// if (ok(r + 1)) {
	// 	ans = r + 1;
	// }
	cout << r << nline;
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
