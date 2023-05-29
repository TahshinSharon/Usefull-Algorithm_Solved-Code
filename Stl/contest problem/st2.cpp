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
	vector<ll>a(n);
	ll sum = 0;
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	if (sum & 1) {
		cout << "NO" << nline;
		return;
	}
	multiset<ll>pre;
	multiset<ll>suf(a.begin(), a.end());
	ll cur = 0;
	ll target = sum / 2;
	for (ll i = 0; i < n; i++) {
		cur += a[i];
		pre.insert(a[i]);
		suf.erase(suf.find(a[i]));
		if (cur == target) {
			cout << "YES" << nline;
			return;
		}
		if (cur > target) {
			ll val = cur - target;
			if (pre.count(val)) {
				cout << "YES" << nline;
				return;
			}
		} else {
			ll val = target - cur;
			if (suf.count(val)) {
				cout << "YES" << nline;
				return;
			}
		}
	}
	cout << "NO" << nline;
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
