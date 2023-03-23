#include<bits/stdc++.h>
using namespace std;
#define ll                  long long
#define ull                 unsigned long long LL
#define md                  10000007
#define pb                  push_back
#define mp                  make_pair
#define pp                  pair<LL,LL>
#define nline "\n"
int bsearch(vector<int>v, int find, int n) {
	int lo = 0, hi = n - 1;
	int mid,ans=0;
	while (lo <= hi) {
		mid = (hi + lo) / 2;
		if (v[mid] < find) {
			ans =mid;
			lo = mid + 1;
		}
		else {
			hi = mid - 1;
		}
	}
}
void solve() {
	int n;
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int find;
	cin >> find;
	int f = bsearch(v, find, n);
	if (f != -1) {
		cout << "The Value" << find << "Found In: " << f << nline;
	}
	else {
		cout << "Not Found" << nline;
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
