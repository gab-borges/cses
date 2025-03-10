#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;

#define N 112345

vector<int> adj[N], rev[N];
vector<bool> visited;

void dfs(int node, vector<int> graph[]) {
	if (visited[node]) return;
	visited[node] = true;

	for (auto nei : graph[node]) {
		dfs(nei, graph);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m; cin >> n >> m;

	while (m--) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		rev[b].push_back(a);
	}

	visited.assign(n+1, false);
	dfs(1, adj);

	for (int i = 1; i <= n; i++)
		if (visited[i] == false) {
			cout << "NO\n";
			cout << "1 " << i << "\n";
			return 0;
		}
	
	visited.assign(n+1, false);
	dfs(1, rev);

	for (int i = 1; i <= n; i++)
		if (visited[i] == false) {
			cout << "NO\n";
			cout << i << " 1" << '\n';
			return 0;
		}
	
	cout << "YES\n";

	return 0;
}

