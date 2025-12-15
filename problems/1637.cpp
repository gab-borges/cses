#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
#define debug(x) cout << #x << " = " << x << '\n';
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << ' '; cout << '\n';
#define vvdebug(a) cout << #a <<" ="<<endl; for(auto &row:a){for(auto &x:row) cout<<x<<' '; cout << endl;}

int maior_digito(int n) {
    int maior = -1;
    do {
        maior = max(maior, n%10);
    } while(n/=10);

    return maior;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    vector<ll> dp(n+1);

    for (int i = 1; i <= 9; i++) dp[i] = 1;

    for (int i = 10; i <= n; i++) {
        int md = maior_digito(i);
        dp[i] = dp[i-md] + 1;
    }

    cout << dp[n] << '\n';

    return 0;
}
