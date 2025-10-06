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
vi visited(MAX_N, false), inStack(MAX_N, false);
vector<vi> adj(MAX_N);
vi ans;

bool dfs(int v) {
    visited[v] = true;
    inStack[v] = true;
    
    for (int u : adj[v]) {
        if (!visited[u]) {
            if (dfs(u))
                return true;
        }
        else if (inStack[u]) {
            return true;
        }
    }

    inStack[v] = false;
    ans.push_back(v);

    return false;
}

bool topsort() {
    for (int i = 1; i <= n; i++)
        if (!visited[i])
            if (dfs(i)) return true;

    reverse(ans.begin(), ans.end());
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a; b;
        adj[a].push_back(b);
    }

    bool temCiclo = topsort();

    if (temCiclo) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    for (auto i : ans)
        cout << i << ' ';
    cout << '\n';

	return 0;
}
