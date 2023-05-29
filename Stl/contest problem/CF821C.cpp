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
	int n;
	cin >> n;
	stack<int>st;
	int cur = 1, ans = 0;
	int i = 0;
	while (i < 2 * n) {
		string s;
		cin >> s;
		if (s[0] == 'a') {
			int x;
			cin >> x;
			st.push(x);
		}
		else if (s[0] == 'r') {
			if (!st.empty()) {
				if (st.top() == cur) {
					st.pop();
				}
				else {
					ans++;
					while (!st.empty()) {
						st.pop();
					}
				}
			}
			cur++;
		}
		i++;
	}
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
