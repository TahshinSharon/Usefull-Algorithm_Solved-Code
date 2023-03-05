#include<bits/stdc++.h>
using namespace std;
#define ll                  long long
#define ull                 unsigned long long LL
#define md                  10000007
#define pb                  push_back
#define mp                  make_pair
#define pp                  pair<LL,LL>
#define nline "\n"
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	double pre[1000001];
	pre[0] = 0;
	for (int i = 1; i < 1000001; i++) {
		pre[i] = pre[i - 1] + log(i);
	}
	int t = 1;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case " << i << ": ";
		int n, base;
		cin >> n >> base;
		ll dig = pre[n] / log(base) + 1;
		cout << dig << nline;
	}
	return 0;
}
