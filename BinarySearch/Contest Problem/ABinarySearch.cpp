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
	int n, k;
	cin >> n >> k;
	vector<int>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		int l = 0, hi = n - 1;
		int f = 0;
		while (l <= hi) {
			int mid = l + (hi - l) / 2;
			if (v[mid] == x) {
				f = 1;
				break;
			}
			else if (v[mid] < x) {
				l = mid + 1;
			}
			else {
				hi = mid - 1;
			}
		}
		if (f) {
			cout << "YES" << nline;
		}
		else {
			cout << "NO" << nline;
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
