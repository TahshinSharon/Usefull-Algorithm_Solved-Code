#include<bits/stdc++.h>
using namespace std;
#define ll                  long long
#define md                  1000007
int a[md + 1];
int arr[md + 1];
ll n;
struct Fenwicktree
{
	ll query(ll idx) {
		ll sum = 0;
		while (idx > 0) {
			sum += a[idx];
			idx -= (idx & -idx);
		}
		return sum;
	}
	void update(ll idx, ll val) {
		while (idx < md) {
			if (idx == 0) {
				break;
			}
			a[idx] += val;
			idx += (idx & -idx);
		}
	}
	ll query(int l, int r) {
		return query(r) - query(l - 1);
	}
};
void solve() {
	cin >> n;
	Fenwicktree fnt;
	ll ans = 0;
	memset(a, 0, sizeof(a));
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++) {
		if (arr[i] == 0) continue;
		ans += fnt.query(arr[i] - 1);
		fnt.update(arr[i], arr[i]);
	}
	cout << ans << endl;
}
int main()
{
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}