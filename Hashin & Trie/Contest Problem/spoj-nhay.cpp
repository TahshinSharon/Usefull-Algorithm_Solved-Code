#include<bits/stdc++.h>
using namespace std;
#define int                 long long
#define ull                 unsigned long long LL
#define md                  10000007
#define pb                  push_back
#define mp                  make_pair
#define pp                  pair<LL,LL>
#define nline "\n"
const int N = 1e6 + 9;
int power(long long n, long long k, const int mod) {
	int ans = 1 % mod;
	n = n % mod;
	if (n < 0) {
		n += mod;
	}
	while (k) {
		if (k & 1) {
			ans = (long long)ans * n % mod;
		}
		n = (long long)n * n % mod;
		k >>= 1;
	}
	return ans;
}
const int mod1 = 127657753, mod2 = 987654319;
const int p1 = 137, p2 = 277;
int ip1, ip2;
pair<int, int>pw[N];
pair<int, int>ipw[N];
void precal() {
	pw[0] = {1, 1};
	for (int i = 1; i < N; i++) {
		pw[i].first = 1LL * pw[i - 1].first * p1 % mod1;
		pw[i].second = 1LL * pw[i - 1].second * p2 % mod2;
	}
	ip1 = power(p1, mod1 - 2, mod1);
	ip2 = power(p2, mod2 - 2, mod2);
	ipw[0] = {1, 1};
	for (int i = 1; i < N; i++) {
		ipw[i].first = 1LL * ipw[i - 1].first * ip1 % mod1;
		ipw[i].second = 1LL * ipw[i - 1].second * ip2 % mod2;
	}
}
struct hashing {
	int n;
	string s;
	vector<pair<int, int>>hs;
	hashing() {}
	hashing(string st) {
		n = st.size();
		s = st;
		hs.emplace_back(0, 0);
		for (int i = 0; i < n; i++) {
			pair<int, int>p;
			p.first = (hs[i].first + 1LL * pw[i].first * s[i] % mod1) % mod1;
			p.second = (hs[i].second + 1LL * pw[i].second * s[i] % mod2) % mod2;
			hs.push_back(p);
		}
	}
	pair<int, int>get_hash(int l, int r) {
		assert(1 <= l && l <= r && r <= n);
		pair<int, int>ans;
		ans.first = ((hs[r].first - hs[l - 1].first + mod1) * 1LL * ipw[l - 1].first) % mod1;
		ans.second = ((hs[r].second - hs[l - 1].second + mod2) * 1LL * ipw[l - 1].second) % mod2;
		return ans;
	}
	pair<int, int>get_hash() {
		return get_hash(1, n);
	}
};
void solve() {
	int n;
	while (cin >> n) {
		string s, p;
		cin >> p >> s;
		hashing h(s);
		hashing ht(p);
		pair<int, int> hs = ht.get_hash();
		for (int i = 1; i + n - 1 <= s.size(); i++) {
			// auto tmp = h.get_hash(i, i + n - 1);
			// cout << tmp.first << " " << hs.first << tmp.second << " " << hs.second << " ";
			if (h.get_hash(i, i + n - 1) == hs) {
				cout << i - 1 << nline;
			}
		}
		cout << nline;
	}
}
int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	precal();
	// cin >> t;
	for (int i = 1; i <= t; i++) {
		//cout<<"Case "<<i<<": ";
		solve();
	}
	return 0;
}
