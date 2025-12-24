#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
#define debug(x) cout << #x << " = " << x << '\n';
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << ' '; cout << '\n';
#define vvdebug(a) cout << #a <<" ="<<endl; for(auto &row:a){for(auto &x:row) cout<<x<<' '; cout << endl;}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;
    vector<vi> dp(a+1, vi(b+1));

    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            if (i == j)
                dp[i][j] = 0;
            else {
                dp[i][j] = INT_MAX;

                for (int k = 1; k * 2 <= i; k++)
                    dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j] + 1);
                for (int k = 1; k * 2 <= j; k++)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j-k] + 1);
            }
        }
    }

    cout << dp[a][b] << '\n';

    return 0;
}
