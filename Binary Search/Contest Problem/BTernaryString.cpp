#include<bits/stdc++.h>
using namespace std;
#define ll                  long long
#define ull                 unsigned long long LL
#define md                  200007
#define pb                  push_back
#define mp                  make_pair
#define pp                  pair<LL,LL>
#define nline "\n"
ll pre[md][5];
ll l;
bool check(ll m) {
	m--;
	for (int i = 0; i <= l - m; i++) {
		ll on = pre[i + m][1] - pre[i - 1][1], tw = pre[i + m][2] - pre[i - 1][2], three = pre[i + m][3] - pre[i - 1][3];
		if (i == 0) {
			on = pre[i + m][1], tw = pre[i + m][2], three = pre[i + m][3];
		}
		if (on && tw && three) {
			return true;
		}
	}
	return false;
}
void solve() {
	string s;
	cin >> s;
	l = s.size();
	for (int i = 0; i < l; i++) {
		for (int j = 1; j <= 3; j++) {
			pre[i + 1][j] = pre[i][j];
		}
		pre[i + 1][s[i] - '0']++;
	}
	ll lo = 0, hi = l, res = 0;
	while (lo <= hi) {
		ll mid = (lo + hi) / 2;
		if (check(mid)) {
			res = mid;
			hi = mid - 1;
		}
		else {
			lo = mid + 1;
		}
	}
	cout << res << nline;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		//cout<<"Case "<<i<<": ";
		solve();
	}
	return 0;
}
