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
	ll n;
	cin >> n;
	string s;
	string ts;
	cin >> s >> ts;
	vector<ll>hash1(n + 1);
	vector<ll>hash11(n + 1);
	vector<ll>hash2(n + 1);
	vector<ll>hash22(n + 1);
	vector<ll>pow(n + 1);
	vector<ll>pow1(n + 1);
	const ll base1 = 1e9 + 181;
	const ll base2 = 1e9 + 193;
	const ll mod = 2e9 + 63;
	pow[0] = 1;
	pow1[0] = 1;
	for (ll i = 1; i <= n; i++) {
		pow[i] = (pow[i - 1] * base1) % mod;
		pow1[i] = (pow1[i - 1] * base2) % mod;
	}
	for (ll i = 1; i <= n; i++) {
		hash1[i] = ((hash1[i - 1] * base1) + (s[i - 1] - 'A' + 1)) % mod;
		hash11[i] = ((hash11[i - 1] * base2) + (s[i - 1] - 'A' + 1)) % mod;
		hash2[i] = ((hash2[i - 1] * base1) + (ts[i - 1] - 'A' + 1)) % mod;
		hash22[i] = ((hash22[i - 1] * base2) + (ts[i - 1] - 'A' + 1)) % mod;
	}
	ll lo = 1, hi = n, start = 1;
	ll mx = 0;
	while (lo <= hi) {
		ll mid = (lo + hi) / 2;
		ll len = mid;
		map<ll, int>m;
		for (ll i = 1; i <= n - len + 1; i++) {
			ll r = i + len - 1;
			ll l = i;
			ll x = (hash1[r] % mod - (hash1[l - 1] * pow[r - l + 1]) % mod) % mod;
			if (x < 0) {
				x += mod;
			}
			ll y = (hash11[r] % mod - (hash11[l - 1] * pow1[r - l + 1]) % mod) % mod;
			if (y < 0) {
				y += mod;
			}
			ll hs = ((x << 32 ) | y);
			m[hs]++;
		}
		int f = 0;
		for (ll i = 1; i <= n - len + 1; i++) {
			ll r = i + len - 1;
			ll l = i;
			ll x = (hash2[r] % mod - (hash2[l - 1] * pow[r - l + 1]) % mod) % mod;
			if (x < 0) {
				x += mod;
			}
			ll y = (hash22[r] % mod - (hash22[l - 1] * pow1[r - l + 1]) % mod) % mod;
			if (y < 0) {
				y += mod;
			}
			ll hs = ((x << 32 ) | y);
			if (m.find(hs) != m.end()) {
				mx = mid;
				start = i;
				f = 1;
				break;
			}
		}
		if (f) {
			lo = mid + 1;
		}
		else {
			hi = mid - 1;
		}
	}
	cout << ts.substr(start - 1, mx) << nline;
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
