#include<bits/stdc++.h>
using namespace std;
#define ll                  long long
#define md                  1000007
int a[md + 1];
int arr[md + 1];
struct Fenwicktree
{
	ll query(ll x, lly) {
		ll sum = 0;
		while (x > 0) {
			int _y = y;
			while (_y > 0) {
				sum += a[x][_y];
				_y -= (_y & -_y);
			}
			x -= (x & -x);
		}
		return sum;
	}
	void update(ll x, ll y, ll val) {
		if (x <= 0 || y <= 0) {
			break;
		}
		while (x < md) {
			int _y = y;
			while (_y < md) {
				a[x][_y] += val;
				_y += (_y & -_y);
			}
			x += (x & -x);
		}
	}
	ll query(int x1, ll y1, ll x2, ll y2) {
		return query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1);
	}
};
void solve() {
	cin >> n;
	Fenwicktree fnt;
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