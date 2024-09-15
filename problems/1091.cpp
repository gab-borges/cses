#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	multiset<int> set;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;

		set.insert(a);
	}

	for (int i = 0; i < m; i++) {
		int t;
		cin >> t;

		if (set.size() == 0) {
			cout << -1 << '\n';
			continue;
		}

		auto it = set.lower_bound(t);

		if (it == set.end()) --it;

		if (*it <= t) {
			cout << *it << '\n';
			set.erase(it);
		}

		else if (it != set.begin() && *(--it) <= t) {
			cout << *(it) << '\n';
			set.erase(it);
		}

		else
			cout << -1 << '\n';
	}

	return 0;
}

