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
    for (int i = 0; i < n; i++) cin >> A[i];

    vi V;
    V.push_back(A[0]);

    for (int i = 1; i < n; i++) {
        if (A[i] > V[V.size() - 1]) {
            V.push_back(A[i]);
        }
        else {
            int w = lower_bound(V.begin(), V.end(), A[i]) - V.begin();
            V[w] = A[i];
        }
    }

    cout << V.size() << '\n';

    return 0;
}
