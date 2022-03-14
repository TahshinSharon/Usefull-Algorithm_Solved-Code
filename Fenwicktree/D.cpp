#include<bits/stdc++.h>
using namespace std;
#define ll                  long long
#define md                  2007
int a[md][md];
int bit[md][md];
struct Fenwicktree {
	ll query(int x, int  y) {
		int sum = 0;
		while (x > 0) {
			int _y = y;
			while (_y > 0) {
				sum += bit[x][_y];
				_y -= (_y & -_y);
			}
			x -= (x & -x);
		}
		return sum;
	}
	void update(int x, int y, int val) {
		if (x <= 0 || y <= 0) {
			return ;
		}
		while (x < md) {
			int _y = y;
			while (_y < md) {
				bit[x][_y] += val;
				_y += (_y & -_y);
			}
			x += (x & -x);
		}
	}
	ll rquery(int x1, int y1, int x2, int y2) {
		return query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1);
	}
};
void solve() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin >> n;
	Fenwicktree fnt;
	memset(bit, 0, sizeof(bit));
	char s[30];
	while (scanf("%s", &s)) {
		cin >> s;
		if (!strcmp(s, "SET")) {
			int x, y, val;
			cin >> x >> y >> val;
			int temp = val - a[x + 1][y + 1];
			a[x + 1][y + 1] = val;
			fnt.update(x + 1, y + 1, temp);
		}
		else if (!strcmp(s, "SUM")) {
			int x1, y1, x2, y2, ans;
			cin >> x1 >> y1 >> x2 >> y2;
			x1++;
			y1++;
			x2++;
			y2++;
			cout << fnt.rquery(x1, y1, x2, y2) << "\n";
		}
		else break;
	}
	cout << "\n";
}
int main()
{
	int t = 1;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}