#include<bits/stdc++.h>
using namespace std;
#define ll                  long long
#define ull                 unsigned long long LL
#define md                  1000007
#define mod                 998244353
#define pb                  push_back
#define mp                  make_pair
#define pp                  pair<LL,LL>
#define nline "\n"
void solve() {
	int n, a, b;
	cin >> n >> a >> b;
	vector<int>v;
	for (int i = 1; i <= 4; i++) {
		v.push_back(a);
	}
	for (int i = 1; i <= 2; i++) {
		v.push_back(b);
	}
	sort(v.begin(), v.end());
	int ans = 6;
	do {
		int x = 1;
		int i = 0;
		int j = n;
		while (i < 6) {
			if (j >= v[i]) {
				j -= v[i];
				i++;
			}
			else {
				j = n;
				x++;
			}
		}
		ans = min(ans, x);
	} while (next_permutation(v.begin(), v.end()));
	cout << ans << nline;
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
