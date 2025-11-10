#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
#define debug(x) cout << #x << " = " << x << '\n';
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << ' '; cout << '\n';
#define vvdebug(a) cout << #a <<" ="<<endl; for(auto &row:a){for(auto &x:row) cout<<x<<' '; cout << endl;}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, x; cin >> n >> x;
    vector<ll> dp(x + 1, LLONG_MAX);
    ll c[n];

    for (int i = 0; i < n; i++) cin >> c[i];

    dp[0] = 0;
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (i - c[j] >= 0) {
                dp[i] = min(dp[i], dp[i - c[j]]);
            }
        }
        if (dp[i] < LLONG_MAX) dp[i]++;
    }

    if (dp[x] == LLONG_MAX) cout << -1 << '\n';
    else cout << dp[x] << '\n';

    return 0;
}
