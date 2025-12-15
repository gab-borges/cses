#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
#define debug(x) cout << #x << " = " << x << '\n';
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << ' '; cout << '\n';
#define vvdebug(a) cout << #a <<" ="<<endl; for(auto &row:a){for(auto &x:row) cout<<x<<' '; cout << endl;}

#define MOD 1'000'000'007

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    vector<vi> A(n, vi(n));
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < n; j++) {
            if (s[j] == '.') A[i][j] = 0;
            else A[i][j] = 1;
        }
    }

    vector<vi> dp(n, vi(n));
    if (A[0][0] == 0) dp[0][0] = 1;

    for (int i = 1; i < n; i++) {
        if (A[0][i] == 0) dp[0][i] = dp[0][i-1];
        if (A[i][0] == 0) dp[i][0] = dp[i-1][0];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (A[i][j] == 0)
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
        }
    }

    cout << dp[n-1][n-1] % MOD << '\n';

    return 0;
}
