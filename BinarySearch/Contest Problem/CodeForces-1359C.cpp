#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define se second
#define fi first
using namespace std;
const int mod = 100000007;
const int N = 2e3 + 10;

ll h, c, t;

long double okay(ll val)
{
	long double hot  = (long double)val * h;
	long double cold = (long double)val * c;

	long double avg = (hot + cold) / (2 * val);

	return abs(avg - t);
}

long double okay1(ll val)
{
	long double hot  = (long double)val * h;
	long double cold = (long double)(val - 1) * c;

	long double avg = (hot + cold) / ((2 * val) - 1);

	return abs(avg - t);
}
void solve(int tc)
{
	ll i, j, m1, m2, l, r;

	cin >> h >> c >> t;

	long double eps = 1e-9;

	l = 1, r = 1e12;

	while ((r - l) > 2)
	{
		m1 = l + (r - l) / 3;
		m2 = r - (r - l) / 3;

		if (okay(m1) <= okay(m2))
		{
			r = m2;
		}
		else
		{
			l = m1;
		}
	}
	ll ans = 0;
	long double temp = 1e15;

	//cout<<l<<' '<<r<<endl;

	for (i = l; i <= r; i++)
	{
		if (okay(i) < temp)
		{
			temp = okay(i);

			ans = 2 * i;
		}
	}



	l = 1, r = 1e12;

	while ((r - l) > 2)
	{
		m1 = l + (r - l) / 3;
		m2 = r - (r - l) / 3;

		if (okay1(m1) <= okay1(m2))
		{
			r = m2;
		}
		else
		{
			l = m1;
		}
	}

	for (i = l; i <= r; i++)
	{
		if (okay1(i) < temp)
		{
			temp = okay1(i);

			ans = 2 * i - 1;
		}
	}
	cout << ans << endl;
}
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//pre();

	int tc = 1;
	cin >> tc;

	for (int test_case = 1; test_case <= tc; test_case++)
	{
		solve(test_case);
	}
	return 0;
}
