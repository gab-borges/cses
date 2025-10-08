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
vi adj[MAX_N], radj[MAX_N], toporder, comp(MAX_N, -1), visited(MAX_N, false);
map<int, int> ans;

void dfs(int node) {
     visited[node] = true;

     for (int nei : adj[node])
         if (!visited[nei])
             dfs(nei);

     toporder.push_back(node);
}

void dfs2(int node, int c) {
    comp[node] = c;

    for (int nei : radj[node])
        if (comp[nei] == -1)
            dfs2(nei, c);
}

void build() {
    for (int i = 1; i <= n; i++)
        if (!visited[i])
            dfs(i);

    reverse(toporder.begin(), toporder.end());

    int c = 0;
    for (int a : toporder) {
        if (comp[a] == -1) {
            ans[c] = a;
            dfs2(a, c++);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
         int a, b;
         cin >> a >> b;

         adj[a].push_back(b);
         radj[b].push_back(a);
    }

    build();

    if (ans.size() == 1) {
        cout << "YES\n";
        return 0;
    }

    cout << "NO\n";
    cout << ans[1] << ' ' << ans[0] << '\n';

    return 0;
}
