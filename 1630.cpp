#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<ii> v;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;

		v.push_back({a, b});
	}


	sort (v.begin(), v.end());

	ll curr = 0, ans = 0;

	for (int i = 0; i < n; i++) {
		curr += v[i].first;
		ans += v[i].second - curr;
	}

	cout << ans << '\n';
	

	return 0;
}

