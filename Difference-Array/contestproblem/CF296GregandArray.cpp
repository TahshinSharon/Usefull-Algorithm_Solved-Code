#include<bits/stdc++.h>
using namespace std;
#define ll                  long long
#define ull                 unsigned long long LL
#define M                   100007
#define pb                  push_back
#define mp                  make_pair
#define pp                  pair<LL,LL>
#define nline "\n"
ll l[M], r[M], d[M];
ll a[M];

ll increment[M];
ll opcount[M];
void solve() {
	ll n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= m; i++) {
		cin >> l[i] >> r[i] >> d[i];
	}
	while (k--) {
		ll x, y;
		cin >> x >> y;
		opcount[x]++;
		opcount[y + 1]--;
	}
	for (int i = 1; i <= m; i++) {
		opcount[i] += opcount[i - 1];
		increment[l[i]] += opcount[i] * d[i];
		increment[r[i] + 1] -= opcount[i] * d[i];
	}
	for (int i = 1; i <= n; i++) {
		increment[i] += increment[i - 1];
		cout << a[i] + increment[i] << " ";
	}
	cout << nline;
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