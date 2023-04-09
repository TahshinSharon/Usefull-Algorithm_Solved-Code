#include<bits/stdc++.h>
using namespace std;
#define ll                  long long
#define ull                 unsigned long long LL
#define md                  10000007
#define pb                  push_back
#define mp                  make_pair
#define pp                  pair<LL,LL>
#define nline "\n"
int ok(int mid, int a, int b, int c) {
	if (a <= mid) {
		int e = mid - a;
		a += min(e, b);
		b -= min(e, b);
	}
	if (c <= mid) {
		int e = mid - c;
		c += min(e, b);
		b -= min(e, b);
	}
	if (b < mid) {
		int e = mid - b;
		if (a > mid && c <= mid) {
			b += min(e, a);
			a -= min(e, a);
		}
		else if (c > mid && a <= mid) {
			b += min(e, c);
			c -= min(e, c);
		}
	}
	return (a <= mid && b <= mid && c <= mid);
}
void solve() {
	int a, b, c;
	cin >> a >> b >> c;
	int lo = 1, hi = 3000;
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		if (ok(mid, a, b, c)) {
			hi = mid;
		}
		else {
			lo = mid + 1;
		}
	}
	cout << lo << nline;
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
