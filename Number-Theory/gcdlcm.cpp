#include<bits/stdc++.h>
using namespace std;
#define ll                  long long
#define ull                 unsigned long long LL
#define md                  10000007
#define pb                  push_back
#define mp                  make_pair
#define pp                  pair<LL,LL>
#define nline "\n"
int gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
int lcm(ll a, ll b) {
	return (a * b) / gcd(a, b);
}
void solve() {
	ll a, b;
	cin >> a >> b;
	cout << "Gcd:" << gcd(a, b) << " " << "Lcm:" << lcm(a, b) << nline;
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
