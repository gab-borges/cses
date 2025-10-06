#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
#define debug(x) cout << #x << " = " << x << '\n';
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << ' '; cout << '\n';
#define vvdebug(a) cout << #a <<" ="<<endl; for(auto &row:a){for(auto &x:row) cout<<x<<' '; cout << endl;}

#define MAX_N 112345
int n, m;
vector<vi> adj(MAX_N);
vector<bool> visited(MAX_N, false);
vi ans, toporder;
vi p(MAX_N, -1);
vector<ll> dist(MAX_N, LLONG_MIN);

void dfs(int node) {
    visited[node] = true;

    for (int nei : adj[node])
        if (!visited[nei])
            dfs(nei);

    toporder.push_back(node);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    dfs(1);
    reverse(toporder.begin(), toporder.end());

    dist[1] = 0;

    for (auto i : toporder) {
        for (auto j : adj[i]) {
            if (dist[i] + 1 > dist[j]) {
                dist[j] = dist[i] + 1;
                p[j] = i;
            }
        }
    }

    if (dist[n] == LLONG_MIN) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    int node = n;
    while (node != -1) {
        ans.push_back(node);
        node = p[node];
    }

    reverse(ans.begin(), ans.end());

    cout << ans.size() << '\n';
    for (auto i : ans)
        cout << i << ' ';
    cout << '\n';

	return 0;
}
