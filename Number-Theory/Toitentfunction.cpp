#include<bits/stdc++.h>
using namespace std;
#define ll                  long long
#define ull                 unsigned long long LL
#define mxn                  10000007
#define pb                  push_back
#define mp                  make_pair
#define pp                  pair<LL,LL>
#define nline "\n"
int spf[mxn];
ll totient(ll n) {
	ll res = n;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			while (n % i == 0) {
				n /= i;
			}
			res -= (res / i);
		}
	}
	if (n > 1) {
		res -= (res / n);
	}
	return res;
}
vector<ll>phi(ll n) {
	vector<ll>v(n + 1);
	for (int i = 0; i <= n; i++) {
		v[i] = i;
	}
	for (int i = 2; i <= n; i++) {
		if (v[i] == i) {
			for (int j = i; j <= n; j += i) {
				v[j] -= (v[j] / i);
			}
		}
	}
	return v;
}
vector<ll>phi_sum(ll n) {
	vector<ll>v(n + 1);
	v[0] = 0;
	v[1] = 1;
	for (int i = 2; i <= n; i++) {
		v[i] = i - 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 2 * i; j <= n; j += i) {
			v[j] -= v[i];
		}
	}
	return v;
}
void solve() {
	ll a, b;
	cin >> a >> b;
	vector<ll>ans = phi_sum(b);
	ll sum = 0;
	for (ll i = a; i <= b; ++) {
		sum += ans[i];
	}
	cout << sum << nline;
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