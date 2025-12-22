#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
#define debug(x) cout << #x << " = " << x << '\n';
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << ' '; cout << '\n';
#define vvdebug(a) cout << #a <<" ="<<endl; for(auto &row:a){for(auto &x:row) cout<<x<<' '; cout << endl;}

#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m; 
    
    vi x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];

    vector<vi> dp(n+2, vi(m+2));

    if (x[0] == 0) {
        for (int v = 1; v <= m; v++)
            dp[0][v] = 1;
    }
    else {
        dp[0][x[0]] = 1;
    }
    
    for (int i = 1; i < n; i++) {
        for (int v = 1; v <= m; v++) {
            if (x[i] != 0 && x[i] != v) {
                dp[i][v] = 0;
                continue;
            }

            ll ways = dp[i-1][v];
            if (v - 1 >= 1) ways = (ways + dp[i-1][v-1]) % MOD;
            if (v + 1 <= m) ways = (ways + dp[i-1][v+1]) % MOD;

            dp[i][v] = ways;
        }
    }
    
    ll ans = 0;

    for (int v = 1; v <= m; v++)
        ans = (ans + dp[n-1][v]) % MOD;

    cout << ans << '\n';

    return 0;
}
