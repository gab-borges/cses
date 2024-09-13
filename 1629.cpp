#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

bool comp (ii &a, ii &b) {
	if (a.second != b.second) return a.second < b.second;

	return a.first < b.first;
}

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

	sort (v.begin(), v.end(), comp);

	int curr = v[0].second;
	int ans = 1;

	for (int i = 1; i < n; i++) {
		if (v[i].first >= curr) {
			ans++;
			curr = v[i].second;
		}
	}

	cout << ans << '\n';

	return 0;
}

