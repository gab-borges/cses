#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
#define debug(x) cout << #x << " = " << x << '\n';
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << ' '; cout << '\n';
#define vvdebug(a) cout << #a <<" ="<<endl; for(auto &row:a){for(auto &x:row) cout<<x<<' '; cout << endl;}

#define N 32
#define M 32
#define K 52

int t;
vector<vector<vi>> dp(N, vector<vi>(M, vi(K, -1)));

ll solve(int n, int m, int k) {
    if (k == 0 || k == n*m) return dp[n][m][k] = 0;
    
    if (k > n*m) return dp[n][m][k] = INT_MAX;

    if (dp[n][m][k] != -1) return dp[n][m][k];

    ll ans = LLONG_MAX;

    for (int i = 1; i < n; i++) {
        ll mindiv = LLONG_MAX;
        for (int x = 0; x <= k; x++) {
            mindiv = min(mindiv, solve(i, m, x) + solve(n-i, m, k-x));
        }
        ans = min(ans, mindiv + m*m);
    }

    for (int j = 1; j < m; j++) {
        ll mindiv = LLONG_MAX;
        for (int x = 0; x <= k; x++) {
            mindiv = min(mindiv, solve(n, j, x) + solve(n, m-j, k-x));
        }
        ans = min(ans, mindiv + n*n);
    }
    
    return dp[n][m][k] = ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;
        ll ans = solve(n, m, k);
        cout << ans << '\n';
    }

    return 0;
}
