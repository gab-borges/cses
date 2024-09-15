#include <bits/stdc++.h>
using namespace std;

#define N 212345

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll n, x;
	cin >> n >> x;

	ll A[N];

	map<ll, int> map;

	for (int i = 0; i < n; i++) {
		cin >> A[i];

		map[A[i]] = i;
	}

	for (int i = 0; i < n; i++) {
		auto it = map.find(x - A[i]);

		if (it != map.end()) {
			int val = map[x - A[i]];

			if (val != i) {
				cout << i + 1 << " " << val + 1 << '\n';
				return 0;
			}
		}
	}

	cout << "IMPOSSIBLE\n";

	return 0;
}

