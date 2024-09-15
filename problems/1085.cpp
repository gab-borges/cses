#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;

ll n, k;
vector<ll> A;

bool f(ll x) {
	ll sum = 0, c = 0;

	for (int i = 0; i < n; i++) {
        if (A[i] > x) return false;

		if (sum + A[i] > x) {
			c++;
			sum = 0;
		}

		sum += A[i];
	}
    
    if (sum > 0) c++;

	return c > k;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> k;
    
    A.assign(n, 0);

	ll sum = 0, maxi = INT_MIN;

	for (int i = 0; i < n; i++) {
		cin >> A[i];

		maxi = max(maxi, A[i]);
		sum += A[i];
	}

	ll lo = maxi, hi = sum;

	while (lo < hi) {
		ll m = (hi + lo) / 2;

		if (f(m)) lo = m + 1;
		else hi = m;
	}

	cout << lo << '\n';

	return 0;
}
