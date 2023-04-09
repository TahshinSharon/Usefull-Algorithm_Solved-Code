#include<bits/stdc++.h>
using namespace std;
#define ll                  long long
#define ull                 unsigned long long LL
#define md                  30000009
#define pb                  push_back
#define mp                  make_pair
#define pp                  pair<LL,LL>
#define nline "\n"
void solve() {
	ll n, m;
	cin >> n >> m;
	vector<ll>a(n + 1);
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		ll k = 0;
		for (auto x : s) {
			k = k * 2 + (x == '1');
		}
		a[i] = k;
	}
	ll len = (1ll << m) - n;
	ll l = 0, h = (1ll << m) - 1, ans = 0;
	while (l <= h) {
		ll mid = (l + h) / 2;
		ll ace = mid + 1;
		for (int i = 0; i < n; i++) {
			if (a[i] <= mid) {
				ace--;
			}
		}
		if (ace >= (len + 1) / 2) {
			ans = mid;
			h = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	for (int i = m - 1; i >= 0; i--) {
		if (ans >> i & 1) {
			cout << '1';
		}
		else {
			cout << '0';
		}
	}
	cout << nline;
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
