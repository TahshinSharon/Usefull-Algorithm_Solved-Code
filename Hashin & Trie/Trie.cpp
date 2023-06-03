#include<bits/stdc++.h>
using namespace std;
#define ll                  long long
#define ull                 unsigned long long LL
#define md                  10000007
#define pb                  push_back
#define mp                  make_pair
#define pp                  pair<LL,LL>
#define nline "\n"
const int N = 10e6 + 7;
int to[N][26];
int tot_node = 1;
int cnt[N];
void add_string(string &s) {
	int cur = 1;
	cnt[cur]++;
	for (int i = 0; i < s.size(); i++) {
		int ch = s[i] - 'a';
		if (!to[cur][ch]) {
			to[cur][ch] = ++tot_node;
		}
		cur = tot_node;
		cnt[cur]++;
	}
}
int query(string &s) {
	int cur = 1;
	for (int i = 0; i < s.size(); i++) {
		int ch = s[i] - 'a';
		if (!to[cur][ch]) {
			return 0;
		}
		cur = to[cur][ch];
	}
	return cnt[cur];
}
void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		add_string(s);
	}
	int q;
	cin >> q;
	while (q--) {
		string s;
		cin >> s;
		int val = query(s);
		if (val) {
			cout << val << nline;
		}
		else {
			cout << "Don't found" << nline;
		}
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
