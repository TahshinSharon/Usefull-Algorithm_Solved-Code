#include<bits/stdc++.h>
using namespace std;
#define ll                  long long
#define ull                 unsigned long long LL
#define md                  10000007
#define pb                  push_back
#define mp                  make_pair
#define pp                  pair<LL,LL>
#define nline "\n"
const int N = int(2e5) + 99;
const int inf = int(1e9) + 99;
int n;
ll s;
pair<int, int>p[N];
bool ok(int mid) {
	ll sum = 0;
	int cnt = 0;
	vector<int>v;
	for (int i = 0; i < n; i++) {
		if (p[i].second < mid) {
			sum += p[i].first;
		}
		else if (p[i].first >= mid) {
			sum += p[i].first;
			cnt++;
		}
		else {
			v.push_back(p[i].first);
		}
	}
	assert(is_sorted(v.begin(), v.end()));
	int need = max(0, (n + 1) / 2 - cnt);
	if (need > v.size()) {
		return false;
	}
	for (int i = 0; i < v.size(); i++) {
		if (i < v.size() - need) {
			sum += v[i];
		}
		else {
			sum += mid;
		}
	}
	return sum <= s;
}
void solve() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> p[i].first >> p[i].second;
	}
	sort(p, p + n);
	int lf = 1, rg = inf;
	while (rg - lf > 1) {
		int mid = (rg + lf) / 2;
		if (ok(mid)) {
			lf = mid;
		}
		else {
			rg = mid;
		}
	}
	cout << lf << nline;
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
