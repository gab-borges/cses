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

    string s; cin >> s;

    ll cont = 1;
    ll ans = 1;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] != s[i-1])
            cont = 0;

        cont++;
        ans = max(ans, cont);
    }

    cout << ans << '\n';

    return 0;
}
