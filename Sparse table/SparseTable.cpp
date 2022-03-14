#include<bits/stdc++.h>
using namespace std;
#define ll                  long long
#define ull                 unsigned long long LL
#define max                  100005
#define nline "\n"
int st[max][20];
int lg[max];
void cal() {
	lg[1] = 0;
	for (int i = 2; i < max; i++) {
		lg[i] = lg[i / 2] + 1;
	}
}
void sparsetable(int ar[], int n) {
	for (int i = 0; i < n; i++) {
		st[i][0] = ar[i];
	}
	for (int j = 1; (1 << j) <= n; j++) {
		for (int i = 0; i + (1 << j) <= n; i++) {
			st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
		}
	}
}
int query(int l, int r) {
	int j = lg[r - l + 1];
	return min(st[l][j], st[(r - (1 << j) + 1)][j]);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cal();
	cin >> t;
	for (int i = 1; i <= t; i++) {

		int n, q;
		cin >> n >> q;
		int a[n];
		for (int j = 0; j < n; j++) {
			cin >> a[j];
		}
		cout << "Scenario #" << i << ":\n";
		sparsetable(a, n);
		for (int j = 0; j < q; j++) {
			int a, b;
			cin >> a >> b;
			cout << query(a - 1, b - 1) << "\n";
		}
	}
	return 0;
}