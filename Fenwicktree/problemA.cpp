#include<bits/stdc++.h>
using namespace std;
#define ll                  long long
#define MOD 1000000007
#define INF 1000000007
#define maxi 1111100
ll int a[maxi + 1];
ll int arr[maxi + 1];
ll query(ll idx) {
	ll sum = 0;
	while (idx > 0) {
		sum += a[idx];
		idx -= (idx & -idx);
	}
	return sum;
}
void update(ll idx, ll val) {
	if (idx <= 0)return;
	while (idx < maxi) {
		a[idx] += val;
		idx += (idx & -idx);
	}
}
void solve() {
	ll n;
	cin >> n;
	ll ans = 0;
	memset(a, 0, sizeof(a));
	for (ll i = 1; i <= n; i++) {
		cin >> arr[i];
		ans += query(arr[i] - 1);
		update(arr[i], arr[i]);
	}
	cout << ans << endl;
}
int main()
{
	int e = 1;
	cin >> e;
	while (e--) {
		solve();
	}
	return 0;
}