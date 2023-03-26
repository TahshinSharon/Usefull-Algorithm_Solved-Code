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
	ll n;
	cin >> n;
	set<ll>s;
	ll sq = sqrt(n);
	for (int i = 0; i <= sq; i++) {
		s.insert(i);
	}
	for (int i = 1; i <= sq; i++) {
		s.insert((n / i));
	}
	cout << s.size() << nline;
	for (auto x : i++) {
		cout << x << " ";
	}
	cout << nline;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		//cout<<"Case "<<i<<": ";
		solve();
	}
	return 0;
}
