#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef pair<ll, ll> llll;
#define N 112345

vector<ii> adj[N];
vector<ll> dist(N, LLONG_MAX);
vector<bool> processed(N, false);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m; cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		adj[a].push_back({b, c});
	}

	priority_queue<llll, vector<llll>, greater<llll>> q;
	dist[1] = 0;
	q.push({0, 1});

	while (!q.empty()) {
		int node = q.top().second; q.pop();

		if (processed[node]) continue;
		processed[node] = true;
		
		for (auto nei : adj[node]) {
			int v = nei.first;
			int weight = nei.second;

			if (dist[node] + weight < dist[v]) {
				dist[v] = dist[node] + weight;
				q.push({dist[v], v});
			}
		}
	}

	for (int i = 1; i <= n; i++)
		cout << dist[i] << ' ';
	cout << '\n';

	return 0;
}
