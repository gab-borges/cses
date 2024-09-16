#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;

ll n;

bool f(ll x) {
	ll c = 0;

	for (ll i = 1; i <= n; i++)
		c += min(n, x/i);

	return (c < (n*n + 1)/2);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	
	ll lo = 1, hi = (n*n);
	
	while (lo < hi) {
		ll m = (lo + hi) / 2;

		if (f(m)) lo = m + 1;
		else hi = m;
	}

	cout << lo << '\n';

	return 0;
}

