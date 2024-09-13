#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

bool comp (ii &a, ii &b) {
	return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;

	vector<ii> movies;

	for (int i = 0;	i < n; i++) {
		int a, b;
		cin >> a >> b;

		movies.push_back({a, b});
	}


	sort (movies.begin(), movies.end(), comp);

	
	priority_queue<int, vector<int>, greater<int>> pq;

	ll ans = 0;

	for (int i = 0; i < n; i++) {
		if (pq.size() < k) {
			pq.push(movies[i].second);
			ans++;
		}

		else if (pq.top() <= movies[i].first) {
			pq.pop();
			pq.push(movies[i].second);
			ans++;
		}

	}

	cout << ans << '\n';

	return 0;
}

