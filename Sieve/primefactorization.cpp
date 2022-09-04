#include<bits/stdc++.h>
using namespace std;
#define ll                  long long
#define ull                 unsigned long long LL
#define md                  10000007
#define pb                  push_back
#define mp                  make_pair
#define pp                  pair<LL,LL>
#define nline "\n"
int spf[mxn];
void sieve() {
	spf[1] = 1;
	for (int i = 2; i < mxn; i++) {
		spf[i] = i;
	}
	for (int i = 4; i < mxn; i += 2) {
		spf[i] = 2;
	}
	for (int i = 3; i * i < mxn; i++) {
		if (spf[i] == i) {
			for (int j = i * i; j < mxn; j += i) {
				if (spf[j] == j) {
					spf[j] = i;
				}
			}
		}
	}
}
vector<int>getfact(int x) {
	vector<int>ret;
	while (x != 1) {
		ret.insert(spf[x]);
		x = x / spf[x];
	}
	return ret;
}
bool prime(int n) {
if (n < 2) return false;
for (int x = 2; x*x <= n; x++) {
if (n%x == 0) return false;
}
return true;
}
void solve() {
	int n;
	cin >> n;
	sieve();
	vector<int>ans = getfact(n);
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
