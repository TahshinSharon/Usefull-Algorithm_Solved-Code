#include<bits/stdc++.h>
using namespace std;
#define ll                  long long
#define ull                 unsigned long long LL
#define md                  10000007
#define pb                  push_back
#define mp                  make_pair
#define pp                  pair<LL,LL>
#define nline "\n"
const ll N = 2e5 + 10;
ll to[N][3];
ll tot_node = 0;
ll cnt[N];
map<pair<ll, ll>, ll>mpp;
ll get_num(char c) {
	if (c >= 0 && c <= 9) {
		return c - '0';
	}
	return c - '0';
}
void add_string(string &s) {
	ll cur = 0;
	ll len = 0;
	for (ll i = 0; i < s.size(); i++) {
		ll ch = get_num(s[i]);
		if (!to[cur][ch]) {
			to[cur][ch] = ++tot_node;
		}
		len++;
		cur = to[cur][ch];
		cnt[cur]++;
		mpp[ {cur, len}] = cnt[cur];
	}
}
void solve() {
	memset(to, 0, sizeof(to));
	memset(cnt, 0, sizeof(cnt));
	tot_node = 0;
	mpp.clear();
	ll n;
	cin >> n;
	string s;
	for (ll i = 0; i < n; i++) {
		cin >> s;
		add_string(s);
	}
	ll ans = 0;
	for (auto it : mpp) {
		ans = max(ans, it.first.second * it.second);
	}
	cout << ans << nline;
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
