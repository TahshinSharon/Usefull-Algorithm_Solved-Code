#include<bits/stdc++.h>
using namespace std;
#define ll                  long long
#define md                  1000007
int a[md + 1];
int arr[md + 1];
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
	int n, q;
	cin >> n >> q;
	Fenwicktree fn;
	while (q--) {
		string s;
		cin >> s;
		if (s == "find") {
			ll a, b;
			cin >> a >> b;
			cout << fn.query(a, b) << endl;
		}
		else {
			ll p, f;
			cin >> p >> f;
			fn.update(p, f);
		}
	}
}
int main()
{
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}