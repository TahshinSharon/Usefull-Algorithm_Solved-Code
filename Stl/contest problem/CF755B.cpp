#include<bits/stdc++.h>
using namespace std;
#define ll                  long long
#define ull                 unsigned long long LL
#define md                  10000007
#define pb                  push_back
#define mp                  make_pair
#define pp                  pair<LL,LL>
#define nline "\n"
void solve() {
	int n, m;
	cin >> n >> m;
	string s[n + m];
	for (int i = 0; i < n + m; i++) {
		cin >> s[i];
	}
	sort(s, s + n + m);
	int cnt = 0;
	for (int i = 0; i < n + m; i++) {
		if (i + 1 == n + m || s[i] != s[i + 1]) {
			cnt++;
		}
	}
	int com = n + m - cnt;
	if ((com + 1) / 2 + (n - com) > (com / 2 + (m - com))) {
		cout << "YES" << nline;
	}
	else {
		cout << "NO" << nline;
	}
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
