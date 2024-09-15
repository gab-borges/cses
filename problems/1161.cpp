#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int x, n;
	cin >> x >> n;

	priority_queue<ll, vector<ll>, greater<ll>> pq;

	for (int i = 0; i < n; i++) {
		ll a;
		cin >> a;

		pq.push(a);
	}

	ll sum = 0;

	while (pq.size() > 1){
		ll a = pq.top();
		pq.pop();
		ll b = pq.top();
		pq.pop();

		ll c = a + b;
		sum += c;
		pq.push(c);
	}

	cout << sum << '\n';

	return 0;
}

