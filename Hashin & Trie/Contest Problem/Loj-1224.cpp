#include<bits/stdc++.h>
using namespace std;
#define int                  long long
#define ull                 unsigned long long LL
#define md                  10000007
#define pb                  push_back
#define mp                  make_pair
#define pp                  pair<LL,LL>
#define nline "\n"
const int N = 1e6 + 7;
int to[N][4];
int tot_node = 0;
int cnt[N];
int ans = 0;
void add_string(string &s) {
	int cur = 0;
	int len = 0;
	for (int i = 0; i < s.size(); i++) {
		int ch;
		if (s[i] == 'A') {
			ch = 0;
		}
		else if (s[i] == 'C') {
			ch = 1;
		}
		else if (s[i] == 'G') {
			ch = 2;
		}
		else if (s[i] == 'T') {
			ch = 3;
		}
		if (to[cur][ch] == 0) {
			to[cur][ch] = ++tot_node;
		}
		len++;
		cur = to[cur][ch];
		cnt[cur]++;
		ans = max(ans, (len * cnt[cur]));
	}
}
void solve() {
	memset(to, 0, sizeof(to));
	memset(cnt, 0, sizeof(cnt));
	tot_node = 0;
	ans = 0;
	int n;
	cin >> n;
	vector<string>s(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		add_string(s[i]);
	}
	cout << ans << nline;
}
int32_t main() {
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
