#include<bits/stdc++.h>
using namespace std;
#define ll                  long long
#define int                 long long
#define ull                 unsigned long long LL
#define md                  10000007
#define pb                  push_back
#define mp                  make_pair
#define pp                  pair<LL,LL>
#define nline "\n"
int t = 1;
vector<int>rabin_karp(string const&s, string const&p) {
	const int base = 47;
	const int mod = 1e9 + 9;
	int S = s.size();
	int P = p.size();
	vector<int>pow(max(S, P));
	pow[0] = 1;
	for (int i = 1; i < (int)pow.size(); i++) {
		pow[i] = (pow[i - 1] * base) % mod;
	}
	vector<ll>hash(S + 1, 0);
	for (int i = 0; i < S; i++) {
		hash[i + 1] = (hash[i] + (s[i] - 'a' + 1) * pow[i]) % mod;
	}
	ll hs = 0;
	for (int i = 0; i < P; i++) {
		hs = (hs + (p[i] - 'a' + 1) * pow[i]) % mod;
	}
	vector<int>v;
	for (int i = 0; i + P - 1 < S; i++) {
		ll c_hash = (hash[i + P] + mod - hash[i]) % mod;
		if (c_hash == (hs * pow[i]) % mod) {
			v.push_back(i + 1);
		}
	}
	return v;
}
void solve(int j) {
	string s;
	string p;
	cin >> s >> p;
	vector<int>ans = rabin_karp(s, p);
	if (ans.empty()) {
		cout << "Not Found" << nline;
	}
	else {
		cout << ans.size() << nline;
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << ((i == ans.size() - 1) ? nline : " ");
		}
	}
	if (j != t)cout << nline;
}
int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	// cin.ignore();
	for (int i = 1; i <= t; i++) {
		//cout<<"Case "<<i<<": ";
		solve(i);
	}
	return 0;
}
