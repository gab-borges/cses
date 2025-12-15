#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;

#define vdebug(x) cout << #x << ': '; for(auto i:x) cout << i << ' '; cout << '\n';

#define MOD 1'000'000'007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, x; cin >> n >> x;
    vi c(n);

    for (int i = 0; i < n; i++)
        cin >> c[i];

    vi dp(x+1);

    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= x; j++) {
            if (j - c[i] >= 0) {
                dp[j] = (dp[j] + dp[j - c[i]]) % MOD;
            }
        }
    }

    cout << dp[x] % MOD << '\n';

    return 0;
}

