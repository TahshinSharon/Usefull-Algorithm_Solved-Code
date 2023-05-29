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
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	ll mx = 0;
	for (int i = 0; i < n; i++) {
		ll c = 1;
		for (int j = i + 1; j < n; j++) {
			if (a[i] <= a[j]) {
				c++;
			}
			else {
				break;
			}
		}
		for (int j = i - 1; j >= 0; j--) {
			if (a[i] <= a[j]) {
				c++;
			}
			else {
				break;
			}
		}
		ll sum = c * a[i];
		mx = max(sum, mx);
	}
	cout << mx << nline;
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
