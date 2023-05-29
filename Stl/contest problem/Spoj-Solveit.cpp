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
	int n, q;
	cin >> n >> q;
	set<int>pq;
	while (q--) {
		int tp, k;
		cin >> tp >> k;
		if (tp == 1) {
			pq.insert(k);
		}
		else {
			if (pq.empty()) {
				cout << -1 << nline;
				continue;
			}
			auto it = pq.end();
			--it;
			if (*it < k) {
				cout << -1 << nline;
				continue;
			}
			auto v = pq.lower_bound(k);
			cout << *v << nline;
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
