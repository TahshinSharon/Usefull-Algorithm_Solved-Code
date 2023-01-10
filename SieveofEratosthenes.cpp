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
vector<int>pm;
int sieve(int n) {
	pm.push_back(2);
	for (int x = 3; x * x <= n; x += 2) {
		if (prime[x] == 0) {
			for (int u = x * x; u <= n; u += 2 * x) {
				prime[u] = 1;
			}
		}
	}
	for (int i = 3; i <= n; i += 2) {
		if (prime[i] == 0)
			pm.push_back(i);
	}
	return pm.size();
}
int is_prime(int n) {
	if (n < 2) return 0;
	for (int x = 2; x * x <= n; x++) {
		if (n % x == 0) return 0;
	}
	return 1;
}
void solve() {
	int n;
	cin >> n;
	cout << sieve(n) << nline;
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