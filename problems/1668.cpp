#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
#define N 112345

int ok = 1;
vi adj[N];
vi group(N, 2);
vector<bool> visited(N, false);

void bfs(int node) {
	queue<int> q;

	q.push(node);
	visited[node] = true;
	group[node] = 1;

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (auto nei : adj[curr]) {
			if (visited[nei]) {
				if (group[nei] == group[curr]) {
					cout << "IMPOSSIBLE\n";
					ok = 0;
					return;
				}

				continue;
			}

			group[nei] = !group[curr];
			visited[nei] = true;
			q.push(nei);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m; cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			bfs(i);

			if (!ok) return 0;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (group[i] == 1) cout << 1 << ' ';
		else cout << 2 << ' ';
	}
	cout << '\n';

	return 0;
}
