#include<bits/stdc++.h>
using namespace std;
#define ll                  long long
#define ull                 unsigned long long LL
#define md                  10000007
#define pb                  push_back
#define mp                  make_pair
#define pp                  pair<LL,LL>
#define nline "\n"
double dis(double x1, double y1, double z1, double x, double y, double z) {
	double tmp = (x1 - x) * (x1 - x) + (y1 - y) * (y1 - y) + (z1 - z) * (z1 - z);
	return sqrt(tmp);
}
void solve() {
	double x1, y1, z1, x2, y2, z2, x, y, z;
	cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> x >> y >> z;
	double disa = sqrt((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y) + (z1 - z) * (z1 - z));
	double disb = sqrt((x2 - x) * (x2 - x) + (y2 - y) * (y2 - y) + (z2 - z) * (z2 - z));
	double ans = 0.0;
	double err = 0.0000000001;
	int it = 100;
	while (it--) {
		double xa = (x1 + (x2 - x1) / 3.0);
		double ya = (2 * y1 + y2) / 3.0;
		double za = (2 * z1 + z2) / 3.0;
		double xb = (x1 + 2 * x2) / 3.0;
		double yb = (y1 + 2 * y2) / 3.0;
		double zb = (z1 + 2 * z2) / 3.0;
		disa = dis(xa, ya, za, x, y, z);
		disb = dis(xb, yb, zb, x, y, z);
		if (disa < disb) {
			x2 = xb;
			y2 = yb;
			z2 = zb;
			ans = disa;
		}
		else {
			x1 = xa;
			y1 = ya;
			z1 = za;
			ans = disb;
		}
	}
	// ans = abs((disa + disb) / 2.0);
	cout << fixed << setprecision(8) << ans << nline;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case " << i << ": ";
		solve();
	}
	return 0;
}
