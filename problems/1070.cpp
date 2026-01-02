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

    if (n == 1) { cout << 1 << '\n'; return 0; }
    if (n <= 3) { cout << "NO SOLUTION\n"; return 0; }
    if (n == 4) { cout << "2 4 1 3\n"; return 0; }

    for (int i = 1; i <= n; i += 2) cout << i << ' ';
    for (int i = 2; i <= n; i += 2) cout << i << ' ';

    cout << '\n';

    return 0;
}
