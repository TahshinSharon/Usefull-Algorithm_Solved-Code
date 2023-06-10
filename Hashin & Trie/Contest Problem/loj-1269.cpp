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
const ll N = 5e6 + 7;
ll to[N][2];
ll tot_node = 0;
ll cnt[N];
void add_bit(ll x) {
	ll cur = 0;
	for (ll i = 31; i >= 0; i--) {
		ll bit = ((x >> i) & 1);
		if (!to[cur][bit]) {
			to[cur][bit] = ++tot_node;
		}
		cur = to[cur][bit];
	}
}
ll qmx(ll x) {
	ll cur = 0;
	ll res = 0;
	for (ll i = 31; i >= 0; i--) {
		ll bit = ((x >> i) & 1);
		if (to[cur][!bit]) {
			res |= (1 << i);
			cur = to[cur][!bit];
		}
		else {
			cur = to[cur][bit];
		}
	}
	return res;
}
ll qmn(ll x) {
	ll cur = 0;
	ll res = 0;
	for (ll i = 31; i >= 0; i--) {
		ll bit = ((x >> i) & 1);
		if (to[cur][bit]) {
			cur = to[cur][bit];
		}
		else {
			res |= (1 << i);
			cur = to[cur][!bit];
		}
	}
	return res;
}
void solve() {
	ll n;
	memset(to, 0, sizeof(to));
	tot_node = 0;
	add_bit(0);
	ll pre_xor = 0;
	ll mx = 0;
	ll mn = LINF;
	cin >> n;
	while (n--) {
		ll x;
		cin >> x;
		pre_xor ^= x;
		mx = max(mx, qmx(pre_xor));
		mn = min(mn, qmn(pre_xor));
		add_bit(pre_xor);
	}
	cout << mx << " " << mn << nline;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case " << i << ": ";
		solve();
	}
	return 0;
}
