#include<bits/stdc++.h>
using namespace std;
#define ll                  long long
#define ull                 unsigned long long LL
#define md                  10000007
#define pb                  push_back
#define mp                  make_pair
#define pp                  pair<LL,LL>
#define nline "\n"
int prime[md];
void int sieve(int n) {
	prime[1] = 1;
	for (int x = 2; x <= n; x++) {
		if (prime[x]) continue;
		for (int u = 2 * x; u <= n; u += x) {
			prime[u] = x;
		}
	}
}
void solve() {
	sieve(n);
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