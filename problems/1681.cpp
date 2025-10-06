#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
#define debug(x) cout << #x << " = " << x << '\n';
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << ' '; cout << '\n';
#define vvdebug(a) cout << #a <<" ="<<endl; for(auto &row:a){for(auto &x:row) cout<<x<<' '; cout << endl;}

#define MAX_N 112345
const ll MOD = 1000000007;
int n, m;
vi adj[MAX_N], toporder;
vector<bool> visited(MAX_N, false);
vector<ll> ans(MAX_N);

void dfs(int node) {
    visited[node] = true;

    for (auto nei : adj[node])
        if (!visited[nei])
            dfs(nei);

    toporder.push_back(node);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
         int a, b; cin >> a >> b;
         adj[a].push_back(b);
    }

    dfs(1);

    reverse(toporder.begin(), toporder.end());

    ans[1] = 1;
    for (auto i : toporder) {
        for (auto j : adj[i]) {
            ans[j] = ((ans[j]%MOD) + (ans[i]%MOD)) % MOD;  
        }
    }

    cout << ans[n] %MOD << '\n';

    return 0;
}
