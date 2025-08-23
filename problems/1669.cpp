#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;

#define N 112345

vi adj[N];
vector<bool> visited(N, false);
vi parent(N, -1);

int cycleStart = -1, cycleEnd = -1;

void dfs(int node, int p) {
	visited[node] = true;
	parent[node] = p;

	for (int nei : adj[node]) {
		if (nei == p) continue;

		if (visited[nei]) {
			cycleStart = nei;
			cycleEnd = node;
			return;
		}

		dfs(nei, node);

		if (cycleStart != -1) return;
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
			dfs(i, -1);

			if (cycleStart != -1) break;
		}
	}

	if (cycleStart == -1) {
		cout << "IMPOSSIBLE\n";
		return 0;
	}

	vi cycle;
	cycle.push_back(cycleStart);

	int curr = cycleEnd;
	while (curr != cycleStart) {
		cycle.push_back(curr);
		curr = parent[curr];
	}

	cycle.push_back(cycleStart);

	reverse(cycle.begin(), cycle.end());

	cout << cycle.size() << '\n';
	
	for (auto i : cycle)
		cout << i << ' ';

	cout << '\n';

	return 0;
}
