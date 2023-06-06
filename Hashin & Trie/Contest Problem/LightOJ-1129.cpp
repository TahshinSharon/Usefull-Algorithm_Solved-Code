#include<bits/stdc++.h>
using namespace std;
#define ll                  long long
#define ull                 unsigned long long LL
#define md                  10000007
#define pb                  push_back
#define mp                  make_pair
#define pp                  pair<LL,LL>
#define nline "\n"
const int N = 1e5 + 7;
int to[N][12];
int tot_node = 1;
int cnt[N * 26 + 100];
void add_string(string &s) {
	int cur = 1;
	for (int i = 0; i < s.size(); i++) {
		int ch = s[i] - '0';
		if (!to[cur][ch]) {
			to[cur][ch] = ++tot_node;
		}
		cnt[cur]++;
		cur = to[cur][ch];
	}
	cnt[cur]++;
}
int query(string &s) {
	int cur = 1;
	for (int i = 0; i < s.size(); i++) {
		int ch = s[i] - '0';
		if (!to[cur][ch]) {
			return 1;
		}
		cur = to[cur][ch];
	}
	return cnt[cur] == 1;
}
void solve() {
	tot_node = 1;
	memset(to, 0, sizeof(to));
	memset(cnt, 0, sizeof(cnt));
	int n;
	cin >> n;
	vector<string>s(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		add_string(s[i]);
	}
	int f = 0;
	for (int i = 0; i < n; i++) {
		int val = query(s[i]);
		// cout << val << " ";
		if (!val) {
			cout << "NO" << nline;
			return;
		}
	}
	cout << "YES" << nline;
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
