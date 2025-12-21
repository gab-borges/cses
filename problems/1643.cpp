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

    int n; cin >> n;
    vi A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    ll ans = 0;
    ll acum = 0;
    for (int i = 0; i < n; i++) {
        acum += A[i];

        if (acum < 0) {
            acum = 0;
        }

        ans = max(ans, acum);
    }

    if (acum == 0) {
        sort(A.begin(), A.end());
        cout << A[A.size()-1] << '\n';
        return 0;
    }

    cout << ans << '\n';

    return 0;
}
