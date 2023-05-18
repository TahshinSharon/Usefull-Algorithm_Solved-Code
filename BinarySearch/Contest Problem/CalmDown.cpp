#include<bits/stdc++.h>
using namespace std;
#define ll                  long long
#define ull                 unsigned long long LL
#define md                  10000007
#define pb                  push_back
#define mp                  make_pair
#define pp                  pair<LL,LL>
#define nline "\n"
double pi = 2 * acos(0.0);
void solve() {
	double R;
	ll n;
	cin >> R >> n;
	double sn = sin(pi / n * 1.0);
	double ans = (R * sn) / (1 + sn * 1.0);
	cout << fixed << setprecision(10) << ans << nline;
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
