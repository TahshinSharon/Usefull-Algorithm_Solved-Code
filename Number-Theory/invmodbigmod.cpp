#include<bits/stdc++.h>
using namespace std;
#define ll                  long long
#define ull                 unsigned long long LL
#define md                  1000000007
#define pb                  push_back
#define mp                  make_pair
#define pp                  pair<LL,LL>
#define nline "\n"
ll bigmod(ll x, ll n, ll mod) {
	if (n == 0) {
		return 1LL;
	}
	ll ret = bigmod(x, n / 2, mod);
	ret = ((ret % mod) * (ret % mod)) % mod;
	if (n % 2 == 1) {
		ret = ((ret % mod) * (x % mod)) % mod;
	}
	return ret;
}
ll powerit(ll x, ll n, ll mod) {
	ll res = 1;
	while (n > 0) {
		if (n % 2) {
			res = ((res % mod) * (a % mod)) % mod;
		}
		a = ((a % mod) * (a % mod)) % mod;
		b /= 2;
	}
	return res % md;
}
ll inverse(ll a, ll m) {
	return powerit(a, m - 2, m);
}
ll ext_gcd(ll a, ll b, ll& x, ll& y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	ll x1, y1;
	ll d = ext_gcd(b, a % b, x1, y1);
	x = y1;
	y = x1 - (a / b) * y1;
	return d;
}
ll modinverse(ll a, ll m) {
	ll x, y;
	ll g = ext_gcd(a, m, x, y);
	if (g != 1) {
		return 0;
	}
	else {
		return ((x % m + m) % m);
	}
}
void solve() {
	ll a, m;
	cin >> a >> m;
	ll res = modinverse(a, m);
	ll ans = inverse(a, m);
	if (res != 0)
		cout << "Mod Inverse of " << a << "=" << res << nline;
	else {
		cout << a << " have no mod inverse value" << nline;
	}
	return;
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