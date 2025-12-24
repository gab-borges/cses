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

    int n;
    cin >> n;

    int maxsum = 0;

    vi A(n);
    for (int i = 0; i < n; i++) { cin >> A[i]; maxsum += A[i]; }

    vi dp(maxsum+1);

    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = maxsum; j >= 0; j--) {
            if (j - A[i-1] >= 0) {
                dp[j] = dp[j] || dp[j-A[i-1]];
            }
        }
    }

    int cont = 0;

    for (int j = 1; j <= maxsum; j++)
        if (dp[j])
            cont++;

    cout << cont << '\n';

    for (int j = 1; j <= maxsum; j++)
        if (dp[j])
            cout << j << ' ';

    cout << '\n';

    return 0;
}
