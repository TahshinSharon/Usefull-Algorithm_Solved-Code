#include<bits/stdc++.h>
using namespace std;
#define ll                  long long
#define ull                 unsigned long long LL
#define md                  10000007
#define pb                  push_back
#define mp                  make_pair
#define nline "\n"
typedef pair<int, int> pt;
int m, n, k, s;
vector<int>l, r, d, a;
bool ok(int x) {
	int tottime = 0;
	vector<pt>seg;
	int mx = int(1e9);
	for (int i = 0; i < x; i++) {
		mx = min(mx, a[i]);
	}
	for (int i = 0; i < k; i++) {
		if (d[i] > mx) {
			seg.push_back(make_pair(l[i], r[i]));
		}
	}
	sort(seg.begin(), seg.end());
	int lastr = 0;
	for (auto tm : seg) {
		if (tm.first <= lastr) {
			tottime += max(0, tm.second - lastr);
			lastr = max(lastr, tm.second);
		}
		else {
			tottime += tm.second - tm.first + 1;
			lastr = tm.second;
		}
	}
	tottime = 2 * (tottime) + n + 1;
	return tottime <= s;
}
void solve() {
	cin >> m >> n >> k >> s;
	a.resize(m);
	for (int i = 0; i < m; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	l.resize(k);
	r.resize(k);
	d.resize(k);
	for (int i = 0; i < k; i++) {
		cin >> l[i] >> r[i] >> d[i];
	}
	int lo = 0, hi = m + 1;
	while (hi - lo > 1) {
		int mid = (lo + hi) / 2;
		if (ok(mid)) {
			lo = mid;
		}
		else {
			hi = mid;
		}
	}
	cout << lo << nline;
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
