#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
#define N 112345

vector<vi> adj;
vi parent(N);
vector<bool> visited(N, false);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m; cin >> n >> m;
	adj.resize(n+1);

	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	queue<int> q;

	q.push(1);

	int ok = 0;
	while (!q.empty()) {
		int node = q.front();
		q.pop();

		if (node == n) {
			ok = 1;
			break;
		}

		for (auto nei : adj[node]) {
			if (visited[nei]) continue;

			parent[nei] = node;

			visited[nei] = true;
			q.push(nei);
		}
	}

	if (!ok) {
		cout << "IMPOSSIBLE\n";
		return 0;
	}

	vi path;

	int cur = n;
	while (cur != 1) {
		path.push_back(cur);
		cur = parent[cur];
	}
	
	path.push_back(1);

	reverse(path.begin(), path.end());

	cout << path.size() << '\n';
	for (auto i : path)
		cout << i << ' ';

	cout << '\n';

	return 0;
}
