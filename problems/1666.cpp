#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;

#define N 112345

vector<int> adj[N];
vector<bool> visited(N, false);

void dfs(int node) {
	if (visited[node]) return;
	visited[node] = true;

	for (auto nei : adj[node])
		if (!visited[nei])
			dfs(nei);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m; cin >> n >> m;

	while (m--) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<int> parts;

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			parts.push_back(i);
			dfs(i);
		}
	}

	int k = parts.size() - 1;

	cout << k << '\n';

	for (int i = 1; i < k + 1; i++) {
		cout << parts[i-1] << " " << parts[i] << '\n';
	}

	return 0;
}

